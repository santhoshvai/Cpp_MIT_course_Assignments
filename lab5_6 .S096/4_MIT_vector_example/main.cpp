#include "vector.h"

int main() {
	Point p; // default constructor
	// p.x is 0.0, p.y is 0.0)
	Point q(2.0, 3.0); // 2-parameter constructor
	// q.x is 2.0, q.y is 3.0)
	Vector r(2.0,3.0,4.0,5.0);
	p.print();
	cout << endl;
	q.print();
	cout << endl;
	r.print();
	p.offset(3.0,4.0);
}
