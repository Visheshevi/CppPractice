#include <stdio.h>

int main(){
  int num;
  printf( "Enter a number ");
  scanf("%d",&num);
  unsigned int even = (num & 0xAAAAAAAA);
  unsigned int odd = (num & 0x55555555);
  even = even >> 1;
  odd = odd << 1;
  printf("%u\n",even|odd);
  return 0;
}
