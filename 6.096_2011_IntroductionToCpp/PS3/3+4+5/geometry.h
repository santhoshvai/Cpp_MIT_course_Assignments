class Point {
  int x, y;

public:
  Point(const int X=0, const int Y=0);
  int getX () const;
  int getY () const;
  void setX ( const int X);
  void setY ( const int Y);
}

class PointArray {
  int _size;
  Point *ptr;

  void resize(int n);

public:
  //constructors
  PointArray(const Point points[], const int size);
  PointArray(const PointArray& pv);
  //destructor
  ~PointArray();
  int getSize () const { return size ;}
  void push_back(const Point &p);
  void insert(const int position, const Point &p);
  void remove(const int pos);
  void clear();
}
class Polygon {
protected:
  static int numPolygons; // track the num of polygons instantiated
  PointArray points;

public:
  Polygon(const Point points[], const int size);
  Polygon(const PointArray &pa);
  virtual double area() const = 0; // = 0 makes it a pure virtual function, hence it is an abstract class
  static int getNumPolygons() { return numPolygons; }
  int getNumSides() const { return points.getSize(); }
  const PointArray *getPoints () const { return &points; }
  ~Polygon() { --numPolygons; }
}
class Rectangle : public Polygon {
public:
  Rectangle ( const Point &a, const Point &b);
  Rectangle ( const int a, const int b, const int c, const int d);
  virtual double area() const ;
}
