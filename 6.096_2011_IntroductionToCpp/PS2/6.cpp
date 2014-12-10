/*
  Section 6 : Array operations

*/
# define LENGTH 4
# define WIDTH 4

void printArray ( const int arr[], const int len ) {
  for(int i = 0; i < len-1; ++i ) {
    cout << arr[i] << ", ";
  }
  cout << arr[len-1];
}

void reverse (int numbers [] , const int numbersLen ) {
  for(int i = 0; i < numbersLen / 2; ++ i ) {
    int tmp = numbers [ i ];
    int indexFromEnd = numbersLen - i - 1; // Gotcha part
    numbers [ i ] = numbers [ indexFromEnd ];
    numbers [ indexFromEnd ] = tmp ;
 }
}

void transpose ( const int input [][ LENGTH ], int output [][ WIDTH ]) {
  for(int i = 0; i < WIDTH ; ++ i ) {
    for(int j = 0; j < LENGTH ; ++ j ) {
      output [ j ][ i ] = input [ i ][ j ];
    }
  }
}
