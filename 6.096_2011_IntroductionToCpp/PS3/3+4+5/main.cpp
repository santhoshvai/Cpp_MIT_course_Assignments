#include <iostream>
#include "./geometry.h"

void printAttributes(Polygon *p) {
  std::cout << "p’s area is " << p->area() << ".\n";
  std::cout << "p’s points are :\n";
  const PointArray *pa = p->getPoints();
  for (int i = 0; i < pa->getSize(); ++i) {
    std::cout << "(" << pa->get(i)->getX() << ", " << pa ->get(i)->getY() << ")\n";
  }
}

int main(int argc, char *argv[]) {
  std::cout << " Enter lower left and upper right coords of rectangle as four space separated integers : ";
  int llx, lly, urx, ury;
  std::cin >> llx >> lly >> urx >> ury;
  Point ll(llx , lly), ur(urx , ury);
  Rectangle r(ll , ur);
  printAttributes(&r);
  std::cout << " Enter three coords of triangle as six space separated integers : ";
  int x1, y1, x2, y2, x3, y3;
  std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  Point a(x1 , y1), b(x2 , y2), c(x3 , y3);
  Triangle t(a, b, c);
  printAttributes(&t);
  return 0;
}
