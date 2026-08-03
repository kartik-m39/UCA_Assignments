#include <stdio.h>

int bang(int x) {
    int minus_x = ~x + 1;
    return ((x | minus_x) >> 31) + 1;
}

int main() {
    printf("%d\n", bang(3));
    printf("%d\n", bang(0));
    
    return 0;
}

