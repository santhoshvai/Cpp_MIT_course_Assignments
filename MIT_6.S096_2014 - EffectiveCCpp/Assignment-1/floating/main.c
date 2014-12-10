/*
PROG: floating
LANG: C
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <string.h>
 
#define ABSOLUTE_WIDTH 31
#define MANTISSA_WIDTH 23
#define EXPONENT_WIDTH 8
// http://easycalculation.com/hex-converter.php
#define EXPONENT_MASK 0xffu // 11111111
#define MANTISSA_MASK 0x007fffffu // 011111111111111111111111 (24 bits)
#define EXPONENT_BIAS 127
 
union float_bits { 
  // example, f = 0.15625
  float f;
  uint32_t bits; // unsigned int = uint32_t
  // 0 01111100 010000000000000000000
  //  |        |
  // sign(1) | exponent(8) | mantissa [fraction] (23)
};
 
void print_float( FILE *output, float f ) {
  union float_bits t; t.f = f;
  uint32_t sign_bit = ( t.bits >> ABSOLUTE_WIDTH ); // get sign the first bit
  uint32_t exponent = ( t.bits >> MANTISSA_WIDTH ) & EXPONENT_MASK; // drop all mantissa bits and mask it with 8 1s
  uint32_t mantissa = ( t.bits  &  MANTISSA_MASK ); // get last 23 bits
 
  if( sign_bit != 0 ) {
    fprintf( output, "-" );
  }
 
  if( exponent > 2 * EXPONENT_BIAS ) { 
    fprintf( output, "Inf\n" ); /* Infinity */
    return;
  } 
  else if( exponent == 0 ) { 
    fprintf( output, "0." ); // Zero or Denormal 
    exponent = ( mantissa != 0 ) ? exponent + 1 : exponent;
  }
  else { 
    fprintf( output, "1." ); /* Usual */
  }
 
  for( int k = MANTISSA_WIDTH - 1; k >= 0; --k ) {
    fprintf( output, "%d", ( mantissa >> k ) & 1 );
  }
 
  if( exponent != 0 || mantissa != 0 ) {
    fprintf( output, " * 2^%d\n", (int) ( exponent - EXPONENT_BIAS ) 
);
  }
}
 
void printTestFile(FILE *input, FILE *output) {
  size_t N; float f;
  fscanf( input, "%zu", &N );
  for( size_t i = 0; i < N; ++i ) {
    fscanf( input, "%f", &f ); // get each float num
    print_float( output, f );
  }
}

int main(int argc, char *argv[]) {
  if ( argc != 2 ) {
    printf("Correct Usage: ./prog [inputfile]\n");
    return 1;
  }

  FILE *input  = fopen( argv[1],  "r" ), 
       *output = fopen( strcat(argv[1], "test"), "w" );
 
  printTestFile(input, output);
  fclose( input );
  fclose( output );
  return 0;
}

