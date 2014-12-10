#include <stdio.h>
#include <stdlib.h>
#define MAXN 100000


void * malloc( size_t bytes ) {
  // magic
}

int array2d[MAXN][MAXN];

int main(void) {
  int **heapArray = malloc( MAXN * 
        sizeof( int* ) );
  for( size_t i = 0; i < MAXN; ++i ) {
    heapArray[i] = malloc( MAXN *
        sizeof( int ) );
  }
  // do stuff
  for( size_t i = 0; i < MAXN; ++i ) {
    free( heapArray[i] );
  }
  free( heapArray );
  return 0;
}
