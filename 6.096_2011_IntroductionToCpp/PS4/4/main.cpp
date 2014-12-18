#include <iostream>
#include "./stack.hpp"

int main() {
  Stack<int> a, b;
  a.push(1);
  a.push(2);
  b.push(3);
  b.push(4);
  Stack<int> c = a + b;
  for (size_t i = 0; i < c.size(); ++i) {
    std::cout << c.get(i) << "\t";
  }
}
