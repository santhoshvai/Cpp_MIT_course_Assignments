
#include <stdio.h>	
class Rectangle {
int * width;
int * height;

public:
Rectangle(int, int); // constructor
~Rectangle(); // destructor

void printMe(){ // 'method' / member function
printf("Dimensions: %d by %d.\n", *width, *height);
}

};
Rectangle::Rectangle(int w, int h){

// constructor definition
width = new int;
height = new int;
*width = w;
*height = h;
}

Rectangle::~Rectangle(){
delete width;
delete height;
}

int main(){
Rectangle box(5, 7);
box.printMe();

}

