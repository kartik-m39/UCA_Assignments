#include <stdio.h>

int logicalShift(int x, int n) {
    int shifted = x >> n;
    int mask = ((1 << 31) >> n) << 1;
    return shifted & ~mask;
}

int main() {
    int test_word = 0x87654321;
    int shift_amount = 4;
    
    int res = logicalShift(test_word, shift_amount); 
    
    printf("0x%08X\n", res);
    
    return 0;
}

