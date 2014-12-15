#include "./geometry.h"
#include <cmath>

// Point
Point::Point(const int X /*= 0*/, const int Y /*= 0*/) {
  x = X;
  y = Y;
}
int Point::getX() const {
  return x;
}
int Point::getY() const {
  return y;
}
void Point::setX(const int X) {
  x = X;
}
void Point::setY(const int Y) {
  y = Y;
}
// PointArray
PointArray::PointArray(const Point points[], const int size) {
  _size = size;
  ptr = new Point[_size];
  for (int i = 0; i < size; ++i) {
    ptr[i] = points[i];
  }
}
PointArray::PointArray(const PointArray& pv) {
  // Any code in the PointArray class has access to
  // private variables like size and points
  _size = pv._size;
  ptr = new Point[_size];
  for (int i = 0; i < _size; ++i) {
    ptr[i] = pv.ptr[i];
  }
}
PointArray::~PointArray() {
  delete[] ptr;
}
/* allocates a new array of size n, copies the first min(previous array size, n) existing
elements into it, and deallocates the old array. */
void PointArray::resize(int n) {
  Point *pts = new Point[n];
  int minSize = n ^ ((_size ^ n) & -(_size < n));  // minimum of two integers, bithack.
  for (int i = 0; i < minSize; ++i) {
    pts[i] = ptr[i];
  }
  delete[] ptr;
  _size = n;
  ptr = pts;
}
// Add a Point to the end of the array
void PointArray::push_back(const Point &p) {
  resize(_size + 1);
  ptr[ _size - 1] = p;
}
// Insert a Point at some arbitrary position (subscript) of the array, shifting the elements
// past position to the right
void PointArray::insert(const int position, const Point &p) {
  resize(_size + 1);
  // shifting previous elems to right
  for (int i = position+1; i < _size; ++i) {
    ptr[i]=ptr[i-1];
  }
  ptr[position] = p;
}
// Remove the Point at some arbitrary position (subscript) of the array, shifting the
// remaining elements to the left
void PointArray::remove(const int pos) {
  if ( pos >= 0 && pos < _size ) {
    for (int i = pos; i < _size-1; ++i) {
      ptr[i] = ptr[i+1];
    }
    resize(_size-1);
  }
}
const int PointArray::getSize() const {
  return _size;
}
void PointArray::clear() {
  resize(0);
}
// Get a pointer to the element at some arbitrary position in the array, where positions
// start at 0 as with arrays
Point *PointArray::get(const int pos) {
  return pos >= 0 && pos < _size ? ptr + pos : NULL;
}
const Point *PointArray::get(const int pos) const {
  return pos >= 0 && pos < _size ? ptr + pos : NULL;
}
// polygon
int Polygon::numPolygons = 0;  // remember to do this

Polygon::Polygon(const Point pts[], const int size) : points(pts, size) {
  ++numPolygons;
}
Polygon::Polygon(const PointArray &pa) : points(pa) {
  ++numPolygons;
}

// rectangle
Point constructorPoints [4];

Point *updateConstructorPoints(const Point &p1 , const Point &p2 , const Point &p3, const Point &p4 = Point(0, 0)) {
  constructorPoints[0] = p1;
  constructorPoints[1] = p2;
  constructorPoints[2] = p3;
  constructorPoints[3] = p4;
  return constructorPoints;
}
Rectangle::Rectangle(const Point &ll, const Point &ur) : Polygon(updateConstructorPoints(ll, Point(ll.getX(), ur.getY()), ur, Point(ur.getX(), ll.getY()) ), 4) {}

Rectangle::Rectangle(const int llx, const int lly, const int urx, const int ury) : Polygon(updateConstructorPoints(Point(llx, lly), Point(llx, ury), Point(urx, ury), Point(urx, lly)), 4) {}

double Rectangle::area() const {
  int length = points.get(1)->getY() - points.get(0)->getY();
  int width = points.get(2)->getX() - points.get(1)->getX();
  return std::abs( static_cast<double>(length) * width );
}

// triangle
Triangle::Triangle(const Point &a, const Point &b, const Point &c) : Polygon(updateConstructorPoints(a, b, c), 3) {}

double Triangle::area() const {
  int dx01 = points.get(0)->getX() - points.get(1)->getX(),
  dx12 = points.get(1)->getX() - points.get(2)->getX(),
  dx20 = points.get(2)->getX() - points.get(0)->getX();
  int dy01 = points.get(0)->getY() - points.get(1)->getY() ,
  dy12 = points .get(1)->getY() - points.get(2)->getY() ,
  dy20 = points .get(2)->getY() - points.get(0)->getY();

  double a = std::sqrt(dx01 * dx01 + dy01 * dy01),
  b = std::sqrt(dx12 * dx12 + dy12 * dy12),
  c = std::sqrt(dx20 * dx20 + dy20 * dy20);

  double s = (a + b + c) / 2;
  return std::sqrt( s * (s-a) * (s-b) * (s-c) );
}
