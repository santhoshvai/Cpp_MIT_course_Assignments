/* Notes: as we will be doing in the class, diagnostic.c should be compiled with
 * "gcc -std=c99 -m64 -Wall -Wextra -Wshadow -Werror -pedantic"
 * (in particular: we are coding by the C99 standard)
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

/************ PROBLEM 8 ************/

bool is_prime( int n ) {
  if( n <= 2 || n % 2 == 0 ) {
    return ( n == 2 );
  }

  for( int i = 3; i * i <= n; i += 2 ) {
    if( n % i == 0 ) {
      return false;
    }
  }

  return true;
}

/************ PROBLEM 9 ************/

void swap( int *a, int *b ) {
  int t = *a;
  *a = *b;
  *b = t;
}

void permute( int *digits, int n, int p ) {
  if( p == n ) {
    for( int i = 0; i < n; ++i ) {
      printf( "%d ", digits[i] );
    }
    printf( "\n" );
  } else {
    for( int i = p; i < n; ++i ) {
      swap( &digits[p], &digits[i] );
      permute( digits, n, p + 1 );
      swap( &digits[p], &digits[i] );
    }
  }
}

void print_permutations( int n ) {
  int *digits = malloc( n * sizeof( int ) );
  for( int i = 0; i < n; ++i ) {
    digits[i] = i + 1;
  }
  permute( digits, n, 0 );
  free( digits );
}

/************ PROBLEM 10 ************/

size_t search( int *data, size_t N, int value ) {
  for( size_t i = 0; i < N; ++i ) {
    if( data[i] == value ) {
      return i;
    }
  }
  return N;
}

size_t binary_search( int *data, size_t N, int value ) {
  size_t lo = 0, hi = N - 1;

  while( lo < hi ) {
    size_t mid = lo + ( hi - lo ) / 2;

    if( data[mid] < value ) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }

  return ( hi == lo && data[lo] == value ) ? lo : N;
}

size_t binary_search2( int *data, size_t N, int value ) {
  long long int lo = 0, hi = N - 1;

  while( lo <= hi ) {
    long long int mid = lo + ( hi - lo ) / 2;

    if( value == data[mid] ) {
      return mid;
    }else if( value < data[mid] ) {
      hi = mid - 1;
    }else{
      lo = mid + 1;
    }
  }

  return N;
}

/************ TESTING ************/

void test_is_prime(void) {
  int N_prime = 10, N_composite = 20;
  int prime[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
  int composite[] = { 1,  4,  6,  8,  9, 10, 12, 14, 15, 16,
                     18, 20, 21, 22, 24, 25, 26, 27, 28, 30 };
                     
  for( int i = 0; i < N_prime; ++i ) {
    assert( is_prime( prime[i] ) );
  }

  for( int i = 0; i < N_composite; ++i ) {
    assert( !is_prime( composite[i] ) );
  }
}

void test_print_permutations(void) {
  print_permutations( 3 );
}

void test_search(void) {
  size_t N = 7;
  int data[] = { 1, 2, 3, 5, 9, 11, 101 };

  assert( search( data, N, 0 ) == 7 );
  assert( search( data, N, 10 ) == 7 );
  assert( search( data, N, 11 ) == 5 );
  assert( search( data, N, 102 ) == 7 );

  assert( binary_search( data, N, 0 ) == 7 );
  assert( binary_search( data, N, 10 ) == 7 );
  assert( binary_search( data, N, 11 ) == 5 );
  assert( binary_search( data, N, 102 ) == 7 );

  assert( binary_search2( data, N, 0 ) == 7 );
  assert( binary_search2( data, N, 10 ) == 7 );
  assert( binary_search2( data, N, 11 ) == 5 );
  assert( binary_search2( data, N, 102 ) == 7 );
}

void run_all_tests(void) {
  test_is_prime();
  test_print_permutations();
  test_search();
}

int main(void) {
  run_all_tests();
  return 0;
}
