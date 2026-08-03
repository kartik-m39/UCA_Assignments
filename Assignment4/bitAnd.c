#include <stdio.h>

int bitAnd(int x, int y) {
  return ~((~x) | (~y));
}

int main(){
  
  int res = bitAnd(6,5);

  printf("%d\n", res);

  return 0;
}
