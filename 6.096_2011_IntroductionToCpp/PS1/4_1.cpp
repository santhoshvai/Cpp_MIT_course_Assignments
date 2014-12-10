/*
Section 4.1 in PS1, in solution pdf it is 3.1

Factorials
*/

#include <iostream>

int main () {
  short number;
  std::cout << " Enter a number : ";
  std::cin >> number ;
  if ( number < 0 ) {
    std::cout << "No negative numbers allowed ";
    return 1;
  }
  std::cout << "The factorial of " << number << " is ";
  unsigned long accumulator = 1; // breaks at N > 65 // if int, N > 19

  for ( ; number > 0; accumulator *= number--); // LOL, just 1 line

  std::cout << accumulator << ".\n";
  return 0;
}
