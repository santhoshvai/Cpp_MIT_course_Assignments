#include <stdio.h>
// define-ed symbols are usually all caps, to distinguish them
#define LENGTH 10

int global_array[LENGTH];

void print_uninitialized_local(void) {
  int local_array[LENGTH];
  for( size_t i = 0; i < LENGTH; ++i ) {
    printf( "local_array[%zu] = %d\n", i, local_array[i] );
  }
}

void print_uninitialized_global(void) {
  for( size_t i = 0; i < LENGTH; ++i ) {
    printf( "global_array[%zu] = %d\n", i, global_array[i] );
  }
}

int main(void) {
  print_uninitialized_local();
  printf( "\n" );
  print_uninitialized_global();

  return 0;
}
