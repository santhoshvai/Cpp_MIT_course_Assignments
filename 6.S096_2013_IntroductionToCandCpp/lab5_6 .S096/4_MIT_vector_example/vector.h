#ifndef _VECTOR_H
#define _VECTOR_H
#include <iostream>
using namespace std;
class Point {
	public:
	double x, y;
	Point() {
	x = 0.0; y = 0.0; cout << "default constructor" << endl;
	}
	Point(double nx, double ny) {
	x = nx; y = ny; cout << "2-parameter constructor" << endl;
	}
	Point(Point &p) {
	x = p.x;
	y = p.y;
	cout <<"copy constructor" << endl;
	}
	void offset(double offsetX, double offsetY);
	void print();
};
class Vector {
	public:
	Point start, end;
	Vector(double sx,double sy,double nx, double ny) {
		start.x = sx; start.y = sy; end.x = nx; end.y = ny;
	       	cout << "4-parameter constructor" << endl;
	}
	void offset(double offsetX, double offsetY);
	void print();
};
#endif
