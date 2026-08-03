#include <stdio.h>

int isPower2(int x) {
    int minus_one = x + ~0;
    int has_single_bit = !(x & minus_one);
    int is_positive = !(x >> 31) & !!x;
    return has_single_bit & is_positive;
}

int main() {
    printf("%d\n", isPower2(5));
    printf("%d\n", isPower2(8));
    printf("%d\n", isPower2(0));
    printf("%d\n", isPower2(-8));
    return 0;
}

