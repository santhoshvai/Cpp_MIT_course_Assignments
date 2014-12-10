#include <stdio.h>

int main(void) {
  int n = 32;
  int count = 0;
  while (n > 1) {
    count++;
    if( n & 1)
        n = n*3 + 1;
    else
        n /= 2;
  }
  printf("%d\n", count);
  return 0;
}
