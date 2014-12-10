/*
PROG: loop
LANG: C
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BLOCK_SIZE 128
 
/* Reverse a string [start,end) */
void reverse( char *begin, char *end ) {
  --end;
  for( char *p = begin; p < end; ++p, --end ) {
    char tmp = *p; *p = *end; *end = tmp;
  }
}
 
void encrypt( char *string, size_t length ) {
  if( length > 2 ) {
    size_t k = length / 2;
 
    reverse( string, string + k );
    reverse( string + k, string + length );
 
    encrypt( string + k, length - k );
    encrypt( string, k );
  }
}
 
void resize_string( char **str, size_t newsize ) {
  if( *str == NULL ) {
    *str = malloc( newsize );
  } else {
    char *tmp = realloc( *str, newsize );
    // If realloc failed, do not change str
    if( tmp == NULL ) {
      fprintf( stderr, "Failed realloc to size %zu.\n", newsize );
    } else {
      *str = tmp;
    }
  }
}
 
size_t getstr( char **str, FILE *input ) {
  size_t chars_to_read = BLOCK_SIZE;
  size_t length = 0;
 
  // If str already exists, we'll append to the end
  if( *str != NULL ) {
    length = strlen( *str );
    while( chars_to_read < length ) {
      chars_to_read <<= 1;
    }
  }
 
  resize_string( str, chars_to_read << 1 );
 
  size_t chars = 0;
  while( ( chars = fread( *str + length, 1, chars_to_read, input ) ) ) {
    length += chars;
    if( chars == chars_to_read ) {
      chars_to_read <<= 1;
      resize_string( str, chars_to_read << 1 );
    } else {
      break; // we're at the end of the file
    }
  }
 
  // Add a terminating '\0' (removing the final newline)
  // and resize to save space
  if( length > 0 ) {
    length = length - 1;
    (*str)[length] = '\0';
    char *tmp = realloc( *str, length + 1 );
    if( tmp != NULL ) {
      *str = tmp;
    }
  }
  return length;
}
 
int main(int argc, char *argv[]) {
  if ( argc != 2 ) {
    printf("Correct Usage: ./prog [inputfile]\n");
    exit( EXIT_FAILURE );
  }

  FILE *input  = fopen( argv[1],  "r" ), 
       *output = fopen( strcat(argv[1], "test"), "w" );

  char *string = NULL;
  size_t length = getstr( &string, input );
  fclose( input );
 
  encrypt( string, length );
 
  fprintf( output, "%zu\n", length );
  fprintf( output, "%s\n", string );
  fclose( output );
 
  free( string );
  return 0;
}