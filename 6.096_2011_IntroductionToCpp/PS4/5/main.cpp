#include "./graph.hpp"
#include <iostream>
#include <cassert>

int main() {
  int first[] = {1, 1, 1, 5, 5, 4};
  std::vector<int> firstVector(first, first + sizeof(first) / sizeof(int) );
  int second[] = {2, 3, 4, 4, 2, 2};
  std::vector<int> secondVector(second, second + sizeof(second) / sizeof(int) );
  Graph gr(firstVector, secondVector);
  std::cout << gr.numOutgoing(1) << std::endl;
  try {
    std::cout << gr.numOutgoing(9);
  } catch(std::exception &error) {
    std::cerr << error.what();
  }
}
