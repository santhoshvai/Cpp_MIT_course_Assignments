#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *array = malloc( 10 * sizeof( int ) );
  for( int i = 0; i < 10; ++i ) {
    array[i] = i;
  }
  free( array );
  return 0;
}
