#include <stdio.h>

int sign(int x){
  int sign_bit = x >> 31;

  int is_nonzero = (x | (~x + 1)) >> 31;

  is_nonzero = is_nonzero & 1;

  return sign_bit | is_nonzero;
}

int main(){
  int res = sign(130);
  int res2 = sign(-23);
  int res3 = sign(0);

  printf("%d\n", res);
  printf("%d\n", res2);
  printf("%d\n", res3);

  return 0;
}
