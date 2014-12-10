#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  This structure will contain the size of our matrix along with
  a dynamically-sized two-dimensional array to store the entries.
*/
typedef struct Matrix_s
{
  size_t R, C;
  int *index;
} Matrix;

/*
  in array x with r rows and c columns
  x[i][j] = (i*c) + j
*/
Matrix* allocate_matrix( size_t R, size_t C ) {
  Matrix *matrix = malloc( sizeof( Matrix ) );
  matrix->R = R;
  matrix->C = C;
  matrix->index = malloc( R * C * sizeof( int ) );
  return matrix;
}

void free_matrix( Matrix *matrix ) {
  free( matrix->index );
  free( matrix );
}

Matrix* read_matrix_naive( FILE *input ) {
  /*
  check out mitSoln.c, transposing and multiplying the matrix makes it
  optimised for cache - due to contiguous access

  http://goo.gl/gsesI4
  */
  size_t R, C;
  fscanf( input, "%zu %zu", &R, &C );
  Matrix *matrix = NULL;
  matrix = allocate_matrix( R, C );
  for( size_t r = 0; r < R; ++r ) {
    for( size_t c = 0; c < C; ++c ) {
      fscanf( input, "%d", &matrix->index[(r * C) + c] );
    }
  }
  return matrix;
}

void print_matrix( Matrix *M, FILE *output) {
  fprintf( output, "%zu %zu\n", M->R, M->C );
  size_t R = M->R, C = M->C;

  for( size_t i = 0; i < R; ++i ) {
    for( size_t j = 0; j < (C - 1); ++j) {
      fprintf( output, "%d ", M->index[(i *C) + j]); // get each int
    }
      fprintf( output, "%d\n", M->index[(i * C) + (C - 1)]); // seperated just to get a line break
  }
}
// see http://i.imgur.com/sRQmp8G.jpg?1
Matrix* multiply_matrix(Matrix *A, Matrix *B) {
  if ( B->R != A->C ) {
    Matrix *M = allocate_matrix( 0, 0 );
    return M;
  }
  Matrix *M = allocate_matrix( A->R, B->C );
  size_t R = M->R, C = M->C, Ac = A->C;

  for( size_t i = 0; i < R; ++i ) {
    for( size_t j = 0; j < C; ++j) {
      M->index[(i * C) + j] = 0;
      for ( size_t k = 0; k < Ac; ++k) {
        M->index[(i * C) + j] += (A->index[(i * Ac) + k]
                                     * B->index[(k * C) + j]);
      }
    }
  }
  return M;
}

void printTestFile(FILE *input, FILE *output) {
  Matrix *A = read_matrix_naive( input );
  Matrix *B = read_matrix_naive( input );
  fclose( input );
  Matrix *A_mul_B = multiply_matrix( A, B);
  print_matrix( A_mul_B, output);
  fclose( output );
  free_matrix( A );
  free_matrix( B );
  free_matrix( A_mul_B );
}

int main(int argc, char *argv[]) {
  if ( argc != 2 ) {
    printf("Correct Usage: ./prog [inputfile]\n");
    exit( EXIT_FAILURE );
  }

  FILE *input  = fopen( argv[1],  "r" ),
       *output = fopen( strcat(argv[1], "test"), "w" );

  printTestFile( input, output );

  exit( EXIT_SUCCESS );
}
