#include "../inc/Span.hpp"

Span::Span(unsigned n) : limit(n) {}
Span::Span(Span const &other) {
  limit = other.limit;
  stack = other.stack;
}
Span &Span::operator=(Span const &other) {
  limit = other.limit;
  stack = other.stack;
  return *this;
}

void Span::addNumber(int n) {
  if (stack.size() + 1 > limit)
    throw std::runtime_error("stack is full");
  else {
    auto stop = std::upper_bound(stack.begin(), stack.end(), n);
    stack.insert(stop, n);
  }
}

#include <iostream>

void Span::print_vector() {
    for (auto it = stack.begin(); it != stack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
void Span::addVector(std::vector<int>::iterator start,
                     std::vector<int>::iterator end) {
  if (stack.size() + std::distance(start, end) > limit)
      throw std::runtime_error("stack is full");
  stack.insert(stack.end(), start, end);
  std::sort(stack.begin(), stack.end());
}


long Span::shortestSpan() {
  if (stack.size() < 2)
    throw std::runtime_error("No enough numbers in stack");
  long shortest = LONG_LONG_MAX;
  for (auto it = stack.begin() + 1; it != stack.end() && shortest != 0; ++it) {
    long a = static_cast<long>(*it) - static_cast<long>(*(it - 1));
    if (a < shortest)
      shortest = a;
  }
  return shortest;
}

long Span::longestSpan() {
    if (stack.size() < 2)
        throw std::runtime_error("Not enough numbers in stack");
    return static_cast<long>(stack.back()) - static_cast<long>(stack.front());
}
