#include <iostream>

// -------------- Interface
class Array {
  size_t _size;
  double *_elem;
  Array( const Array& );
  Array& operator=( const Array& );
public:
  Array( size_t theSize );
  ~Array();

  inline size_t size() const { return _size; };

  double& operator[]( size_t i );
  double operator[] ( size_t i ) const;
  void print() const;
};

// -------------- Implementation
Array::Array( size_t theSize ) : _size{theSize}, _elem{new double[theSize]} {
  for( size_t i = 0; i < _size; ++i ) {
    _elem[i] = 0;
  }
}

Array::~Array() {
  delete [] _elem;
}

double& Array::operator[]( size_t i ) {
  return _elem[i];
}

double Array::operator[]( size_t i ) const {
  return _elem[i];
}

void Array::print() const {
  std::cout << "[ ";

  for( size_t i = 0; i < _size; ++i ) {
    std::cout << _elem[i] << " ";
  }

  std::cout << "]\n";
}


int main() {
  Array array{ 10 };

  for( size_t i = 0; i < array.size(); ++i ) {
    array[i] = i;
  }

  array.print();
  return 0;
}
