#include "./main.hpp"
#include <cassert>
#include <iostream>

int main() {
  assert(minimum(9, 10) == mini(9, 10));
  assert(minimum("santhosh", "vaiyapuri") == mini("santhosh", "vaiyapuri"));
  std::cout << "All asserts passed";
}
