#include <stdio.h>

int getByte(int x, int n) {
    return (x >> (n << 3)) & 0xFF;
}

int main() {
    int test_word = 0x12345678;
    
    int res = getByte(test_word,1); 
    printf("0x%X\n", res);
    
    return 0;
}
