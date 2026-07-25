#include <stdio.h>

void process_stream() {
    int c, next;

    while ((c = getchar()) != EOF) {
        if (c == '/') {
            next = getchar();

            if (next == '/') {
                while ((c = getchar()) != EOF && c != '\n');
                if (c == '\n') putchar('\n');
            } 
            else if (next == '*') {
                int prev = 0;
                while ((c = getchar()) != EOF) {
                    if (prev == '*' && c == '/') break;
                    prev = c;
                }
            } 
            else {
                putchar(c);
                if (next != EOF) putchar(next);
            }
        } 
        else if (c == '"' || c == '\'') {
            int quote = c;
            putchar(c);
            while ((c = getchar()) != EOF) {
                putchar(c);
                if (c == '\\') {
                    if ((c = getchar()) != EOF) putchar(c);
                } else if (c == quote) {
                    break;
                }
            }
        } 
        else {
            putchar(c);
        }
    }
}

int main() {
    process_stream();
    return 0;
}