#ifndef STACK_HPP_
#define STACK_HPP_

#include <vector>
template <class T> class Stack;

template <class T>
Stack<T> operator+(const Stack<T> &s1, const Stack<T> &s2) {
  Stack<T> result = s1;
  for (size_t i = 0; i < s1.st.size(); ++i) {
    result.st.push_back(s2.st[i]);
  }
  return result;
}

template <class T>
class Stack {
  friend Stack<T> operator+<>(const Stack<T> &s1, const Stack<T> &s2);
  std::vector<T> st;  // an empty vector

 public:
  bool empty() { return st.empty(); }
  void push(const T &item) { st.push_back(item); }
  T &top() {  // – returns a reference to the most-recently-added item
    T last = st.back();  // access last element
    return last;
  }
  void pop() {
    st.pop_back();  // delete last element
  }
  size_t size() {
    return st.size();
  }
  T get(size_t i) {
    return st[i];
  }
};

#endif  // STACK_HPP_
