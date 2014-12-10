/*
  Section 5 : Calculation Pi

  PI is the ratio of circle-circumference vs diameter

  Area of circle = PI * r^2
  4(a/4) = PI * r^2
  PI = 4(a/4)/r^2

  a/4 is dartsInCircle/totalNoOfDarts

  # With enough darts, the ratio of darts in the circle to total darts thrown
  # should be the ratio between the area of the circle-quadrant (a/4)
  # and the area of the square-quadrant (1) = a/4.

*/
#include <cmath>
#include <iostream>
#include <cstdlib>

double computePi ( const int n ) {
  srand ( time (0) );
  int dartsInCircle = 0;
  for(int i = 0; i < n ; ++i ) {
    double x = rand () / ( double ) RAND_MAX, y = rand () / ( double ) RAND_MAX;
    if( sqrt ( x * x + y * y ) < 1 ) {
      ++ dartsInCircle ;
    }
  }
 // r^2 is 1 , and a/4 = dartsInCircle /n, yielding this for pi:
 return dartsInCircle / static_cast <double>(n ) * 4;
 // static cast doesnt checkup in runtime, we know that int can be converted to double for sure so use static cast
 // dynamic_cast is when u want to perform a runtime check (for inherited classes), has performance overhead
}

int main () {
  int n=0;
  std::cout << "Enter the number of dart throws: ";
  std::cin >> n;
  std::cout << "The value of pi is: " << computePi( n ) << std::endl;
}
