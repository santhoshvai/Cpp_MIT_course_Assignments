#include <stdio.h>
#include <stdlib.h>

void static_alloc(void) {
  int array[10];
  int array2[] = { 1, 2, 3, 4, 5 };
  char str[] = "blah";

  printf( "Statically allocated:\n" );
  printf( "\tarray  = %p\n", (void*) array );
  printf( "\tarray2 = %p\n", (void*) array2 );
  printf( "\tstr    = %p\n", (void*) str );
}

void dynamic_alloc(void) {
  // malloc accepts a size_t number of bytes
  int *array = malloc( 10 * sizeof( int ) );

  printf( "Dynamically allocated:\n" );
  printf( "\tarray = %p\n", (void*) array );
  free( array );
}

int main(void) {
  static_alloc();
  dynamic_alloc();
  return 0;
}
