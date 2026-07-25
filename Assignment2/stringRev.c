#include <stdio.h>

void reverse_string(char *str) {
    int left = 0;
    int right = 0;
    char temp;

    // Find the length of the string
    while (str[right] != '\0') {
        right++;
    }

    right--; // Point to the last character

    // Swap characters from both ends
    while (left < right) {
        temp = str[left];
        str[left] = str[right];
        str[right] = temp;

        left++;
        right--;
    }
}

int main() {
    char str[] = "Data Structures";

    reverse_string(str);

    printf("%s\n", str);

    return 0;
}
