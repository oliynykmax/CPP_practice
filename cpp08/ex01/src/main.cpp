#include "../inc/Span.hpp"
#include <iostream>
#include <random>

void test_with_a_size(unsigned int size) {
    std::cout << "Testing with size: " << size << std::endl;
    Span sp(size);
    std::vector<int> vec;
    vec.reserve(size);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<double> noise(0, 2000);
    std::uniform_int_distribution<int> base(-1000000, 1000000);

    for (unsigned int i = 0; i < size; ++i) {
        int val = base(gen) + static_cast<int>(noise(gen));
        vec.push_back(val);
    }


    sp.addVector(vec.begin(), vec.end());
    std::cout << "shortestSpan: " << sp.shortestSpan() << '\n';
    std::cout << "longestSpan:  " << sp.longestSpan() << '\n';
    // sp.print_vector();
}

int main() {
  Span sp = Span(5);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;

  std::cout << "\nNow good test" << std::endl;
  test_with_a_size(100);
  test_with_a_size(1000);
  test_with_a_size(10000);
  test_with_a_size(100000);
  test_with_a_size(1000000);

  Span sp2 = Span(1);
  try {
    sp2.addNumber(1);
    sp2.addNumber(2);
    sp2.addNumber(3);
  } catch (const std::exception& e) {
    std::cerr << "Exception caught: " << e.what() << std::endl;
  }
  try {
      sp2.shortestSpan();
      sp2.longestSpan();
  } catch (const std::exception& e) {
    std::cerr << "Exception caught: " << e.what() << std::endl;
  }

  return 0;
}
