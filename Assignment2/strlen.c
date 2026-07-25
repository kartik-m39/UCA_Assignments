#include <stdio.h>

int my_strlen(const char *str) {
    int length = 0;

    while (str[length] != '\0') {
        length++;
    }

    return length;
}

int main() {
    const char str[] = "Hello World";

    int length = my_strlen(str);

    printf("Length of string: %d\n", length);

    return 0;
}
