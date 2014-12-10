/*
Section 3.5.1 in PS1, in solution pdf it is 2.5.1

Russian peasant multiplication

http://mathforum.org/dr.math/faq/faq.peasant.html
*/
#include <iostream>
#include <omp.h>
#include <cassert>
#include <string>

void mitSoln(int bob, int dole) {
  int accumulator = 0;
  while ( true ) {
    if( dole == 0) break ;
    accumulator += (( dole % 2 == 1) ? bob : 0);
    dole /= 2;
    bob *= 2;
  }
  assert( accumulator == 4902 );
}
// just added some bit twiddling hacks
void sanSoln(int bob, int dole) {
  int accumulator = 0;
  while ( true ) {
    if( dole == 0) break ;
    accumulator += (( dole & 1 ) ? bob : 0);
    dole >>= 1;
    bob <<= 1;
  }
  assert( accumulator == 4902 );
}

// compile as g++ -std=c++11 3_5_1.cpp -fopenmp
int main() {
  int bob = 57, dole = 86;
  double start = omp_get_wtime();
  mitSoln (bob, dole);
  double end = omp_get_wtime();
  sanSoln (bob, dole);
  double end2 = omp_get_wtime();
  std::cout << "MIT_Soln : " << (end - start) << std::endl; // 8^e-7
  std::cout << "SAN_Soln : " << (end2 - end) << std::endl; // 4^e-7
}
