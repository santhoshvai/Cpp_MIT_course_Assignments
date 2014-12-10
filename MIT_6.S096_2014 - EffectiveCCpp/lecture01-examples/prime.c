#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <errno.h>

bool is_prime( long int n ) {
  if( n <= 2 || n % 2 == 0 ) {
    return ( n == 2 );
  }

  for( long int i = 3; i * i <= n; i += 2 ) {
    if( n % i == 0 ) {
      return false;
    }
  }

  return true;
}

// For example: ./prime 31
void usage( char *progname ) {
  printf( "Usage: %s [number to check for primality]\n", progname );
}

int main( int argc, char **argv ) {
  if( argc != 2 ) {
    usage( argv[0] );
    return EXIT_FAILURE;
  }

  // Convert a string to integer in base 10
  long int n = strtol( argv[1], NULL, 10 );

  // Check errno to make sure the number is valid
  if( errno == ERANGE ) {
    printf( "Error: number '%s' provided is not valid.\n", argv[1] );
    return EXIT_FAILURE;
  }

  if( is_prime( n ) ) {
    printf( "%ld is prime.\n", n );
  } else {
    printf( "%ld is not prime.\n", n );
  }
  return 0;
}
