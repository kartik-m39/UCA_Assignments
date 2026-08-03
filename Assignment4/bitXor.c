#include <stdio.h>

int bitXor(int x, int y) {
  return (~(x & y) & ~(~x & ~y));
}

int main(){
  
  int res = bitXor(4,5);

  printf("%d\n", res);

  return 0;
}

