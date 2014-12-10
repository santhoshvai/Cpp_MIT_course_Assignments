#include <stdio.h>

int main(void) {
  int a = 5;
  int *a_ptr = &a;

  printf( "&a     : %p : 0x%012x : a\n", (void*) &a, a );
  printf( "&a_ptr : %p : %p : a_ptr\n",  (void*) &a_ptr, 
                                         (void*) a_ptr );
  return 0;
}
