#include <stdio.h>

int global_array[100];

int main(void) {
  size_t N = 10;

  for( size_t i = 0; i < N; ++i ) {
    global_array[i] = i;
  }

  /* This loop does functionally the same thing as the previous 'for' */
  size_t i = 0;
  while( i < N ) {
    printf( "global_array[%zu] = %d\n", i, global_array[i] );
    ++i;
  }


  return 0;
}
