#include <stdio.h>

int fitBits(int x, int n) {
  int shift = 32 + (~n + 1);
  int signExtended = (x << shift) >> shift;
  return !(x ^ signExtended);
}

int main(){
  
  int res = fitBits(5,3);
  int res2 = fitBits(-4, 3);

  printf("%d\n", res);
  printf("%d\n", res2);

  return 0;
}


