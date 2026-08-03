#include <stdio.h>

int conditional(int x, int y, int z) {
    int mask = ((!x) << 31) >> 31;
    return (mask & z) | (~mask & y);
}

int main() {
    printf("%d\n", conditional(2, 4, 5));
    return 0;
}

