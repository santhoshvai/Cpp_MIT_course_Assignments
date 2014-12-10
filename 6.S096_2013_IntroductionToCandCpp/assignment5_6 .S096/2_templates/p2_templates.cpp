#include <stdio.h>
typedef struct Point_ {
    int x;
    int y;
} Point;

template <typename T>
class List {
	T * list;
	
public:
	int length;
	
	List(int len) {
		list = new T[len];
		length = len;
	}
	
	~List() {
		delete[] list;
	}
	
	T get(int index) {
		return list[index];
	}
	
	void set(int index, T val) {
		list[index] = val;
	}
};

/*
template <>
class List <Point *> {
	Point **list;
	
public:
	int length;
	
	List(int len) {
		list = new Point*[len];  //create an array of pointers
		length = len;
	}
	
	~List() {
		delete[] list;
	}
	
	Point* get(int index) {
		return list[index];
	}
	
	void set(int index, Point * val) {
		list[index] = val;
	}
};
* /

/*
    You shouldn't change the code below, unless you want to _temporarily_ change the main function while testing.
    Change it back when you're done.    
*/


int main(){
  List<int> integers(10);
    for(int i = 0; i < integers.length; i++){
        integers.set(i, i * 100);
        printf("%d ", integers.get(i));
    }
    printf("\n"); // this loop should print: 0 100 200 300 400 500 600 700 800 900 
 
   List<Point *> points(5);
    for(int i = 0; i < points.length; i++){
        Point * p = new Point;
        p->x = i * 10;
        p->y = i * 100;
        points.set(i, p);
        printf("(%d, %d) ", points.get(i)->x, points.get(i)->y);
        delete p;
    }
    printf("\n"); // this loop should print: (0, 0) (10, 100) (20, 200) (30, 300) (40, 400) 

}
