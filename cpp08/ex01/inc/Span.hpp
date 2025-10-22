#pragma once

#include <algorithm>
#include <climits>
#include <stdexcept>
#include <vector>
class Span {
private:
  std::vector<int> stack;
  size_t limit;

public:
  Span() = delete;
  Span(unsigned n);
  Span(Span const &other);
  Span &operator=(Span const &other);
  ~Span() = default;

  void addVector(std::vector<int>::iterator start,
                 std::vector<int>::iterator end);
  void addNumber(int n);
  long shortestSpan();
  long longestSpan();
  void print_vector();
};
