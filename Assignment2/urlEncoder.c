#include <stdio.h>

void url_encode(char *str, int true_length) {
    int space_count = 0;

    // Count spaces in the true length
    for (int i = 0; i < true_length; i++) {
        if (str[i] == ' ') {
            space_count++;
        }
    }

    
    int new_length = true_length + (space_count * 2);

    
    str[new_length] = '\0';

    
    int i = true_length - 1;
    int j = new_length - 1;

    while (i >= 0) {
        if (str[i] == ' ') {
            str[j--] = '0';
            str[j--] = '2';
            str[j--] = '%';
        } else {
            str[j--] = str[i];
        }
        i--;
    }
}

int main() {
    char str[50] = "Hello World   ";
    int true_length = 11;  

    url_encode(str, true_length);

    printf("%s\n", str);

    return 0;
}
