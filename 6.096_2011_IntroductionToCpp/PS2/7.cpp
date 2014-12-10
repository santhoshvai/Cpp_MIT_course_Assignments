/*
  Section 7: Pointers and Strings
*/
#include <cassert>

int stringLength ( const char * str ) {
  int length = 0;
  while (*( str + length ) != ’ \0 ’) {
    ++length ;
  }
  return length;
}
/*
void swap (int &x, int & y ) {
  int tmp = x ;
  x = y ;
  y = tmp;
}
*/

// rewrite the above swap fn using pointers
/*
void swap (int *x , int * y ) {
  int tmp = * x ;
  *x = *y ;
  *y = tmp ;
}
*/
//  instead of swapping two values, it swaps two pointers to point to each other’s values.
void swap (int **x , int **y ) {
  int *tmp = *x ;
  *x = *y ;
  *y = tmp ;
}

int main () {
  int x = 5, y = 6;
  int *ptr1 = &x, *ptr2 = &y;
  swap (&ptr1 , &ptr2) ;
  assert( *ptr1 == 6 );
  assert(*ptr2 == 5 );
}
