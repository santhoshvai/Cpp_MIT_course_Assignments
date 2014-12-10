/*
PROG: matrix
LANG: C
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 300
/*
  this structure will contain the size of our matrix
  along with a statically-sized two-dimensional array
  to store the entries
*/
typedef struct Matrix_s
{
  size_t R, C;
  int index[MAXN][MAXN];
} Matrix;

void getMatrix( Matrix *M, FILE *input) {
  fscanf( input, "%zu %zu", &M->R, &M->C );
  for( size_t i = 0; i < M->R; ++i ) {
    for( size_t j = 0; j < M->C; ++j) {
      fscanf( input, "%d", &M->index[i][j]); // get each int
    }
  }
}

void printMatrix( Matrix *M, FILE *output) {
  fprintf( output, "%zu %zu\n", M->R, M->C );
  for( size_t i = 0; i < M->R; ++i ) {
    for( size_t j = 0; j < (M->C - 1); ++j) {
      fprintf( output, "%d ", M->index[i][j]); // get each int
    }
      fprintf( output, "%d\n", M->index[i][M->C - 1]); // seperated just for a line break
  }
}

void multiplyMatrix(Matrix *A, Matrix *B, Matrix *M) {
  if ( B->R != A->C ) {
    M->R = 0;
    M->C = 0;
    return;
  }
  M->R = A->R;
  M->C = B->C;
  for( size_t i = 0; i < M->R; ++i ) {
    for( size_t j = 0; j < M->C; ++j) {
      M->index[i][j] = 0;
      for ( size_t k = 0; k < A->C; ++k) { // columns of A
        // A matrix --- 1 row, multiple columns  (i, k)
        // B matrix --- multiple rows, 1 column  (k, j)
        M->index[i][j] += (A->index[i][k] * B->index[k][j]);
      }
    }
  }
}

void printTestFile(FILE *input, FILE *output) {
  Matrix A, B, A_mul_B;
  getMatrix( &A, input );
  getMatrix( &B, input );

  multiplyMatrix( &A, &B, &A_mul_B);
  printMatrix( &A_mul_B, output);
}

int main(int argc, char *argv[]) {
  if ( argc != 2 ) {
    printf("Correct Usage: ./prog [inputfile]\n");
    exit( EXIT_FAILURE );
  }

  FILE *input  = fopen( argv[1],  "r" ),
       *output = fopen( strcat(argv[1], "test"), "w" );

  printTestFile(input, output);
  fclose( input );
  fclose( output );
  exit( EXIT_SUCCESS );
}
