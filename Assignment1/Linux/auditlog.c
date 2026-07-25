
#include <fcntl.h>   
#include <unistd.h>  
#include <string.h>  
 
#define LOGFILE "auditlog.log"
#define BUF_SIZE 65536   
 
// Small helper: writing a whole string out to a file descriptor.
void write_str(int fd, const char *s) {
    write(fd, s, strlen(s));
}
 
// Adding a message to the log file
void do_add(const char *message) {
    int fd = open(LOGFILE, O_WRONLY | O_CREAT | O_APPEND, 0644);
 
    write_str(fd, message);
    write_str(fd, "\n"); 

    close(fd);
}
 
void do_view(void) {
    int fd = open(LOGFILE, O_RDONLY);
    if (fd < 0) return;   
 
    static char data[BUF_SIZE];
    int len = read(fd, data, BUF_SIZE - 1);  // read whole file in one go
    close(fd);
 
    if (len <= 0) return;
 
    int lineno = 1;
    int start = 0;
 
    // Walking through the buffer and printing every line we find
    for (int i = 0; i < len; i++) {
        if (data[i] == '\n') {
            char num[8];
            int n = lineno, j = 0;
 
            // convert lineno to a string by hand (no sprintf)
            char tmp[8];
            int t = 0;
            if (n == 0) tmp[t++] = '0';
            while (n > 0) { tmp[t++] = '0' + (n % 10); n /= 10; }
            while (t > 0) num[j++] = tmp[--t];
            num[j] = '\0';
 
            write_str(1, num);          // fd 1 = stdout
            write_str(1, ": ");
            write(1, data + start, i - start);  // the line's text itself
            write_str(1, "\n");
 
            lineno++;
            start = i + 1;
        }
    }
}
 
int main(int argc, char **argv) {
    if (argc >= 3 && strcmp(argv[1], "--add") == 0) {
        do_add(argv[2]);
    } else if (argc >= 2 && strcmp(argv[1], "--view") == 0) {
        do_view();
    } else {
        write_str(2, "Usage: auditlog --add \"msg\"  |  auditlog --view\n");
        return 1;
    }
    return 0;
}
 
