#include "../inc/PmergeMe.hpp"
#include <chrono>
#include <iomanip>
#include <iostream>

template <typename Container> bool is_sorted(const Container &c) {
  for (size_t i = 1; i < c.size(); ++i) {
    if (c[i] < c[i - 1]) {
      return false;
    }
  }
  return true;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "Error: no elements" << std::endl;
    exit(1);
  }

  std::cout << "Before: ";
  for (int i = 1; i < argc; ++i) {
    std::cout << argv[i] << " ";
  }
  std::cout << std::endl;

  std::chrono::steady_clock::time_point start_vec =
      std::chrono::steady_clock::now();
  std::vector<int> result_vec = sort_vector(argc, argv);
  std::chrono::steady_clock::time_point end_vec =
      std::chrono::steady_clock::now();

  std::cout << "After: ";
  for (size_t i = 0; i < result_vec.size(); ++i) {
    std::cout << result_vec[i] << " ";
  }
  std::cout << std::endl;

  if (is_sorted(result_vec)) {
    std::cout << "sorted correctly!\n";
  } else {
    std::cout << "NOT sorted!\n";
  }

  std::chrono::steady_clock::time_point start_deq =
      std::chrono::steady_clock::now();
  std::deque<int> result_deq = sort_deque(argc, argv);
  std::chrono::steady_clock::time_point end_deq =
      std::chrono::steady_clock::now();

  std::cout << "Time to process a range of " << result_vec.size()
            << " elements with std::vector : " << std::fixed
            << std::setprecision(5)
            << std::chrono::duration_cast<std::chrono::nanoseconds>(end_vec -
                                                                    start_vec)
                       .count() /
                   1000.0
            << " us" << std::endl;
  std::cout << "Time to process a range of " << result_deq.size()
            << " elements with std::deque : " << std::fixed
            << std::setprecision(5)
            << std::chrono::duration_cast<std::chrono::nanoseconds>(end_deq -
                                                                    start_deq)
                       .count() /
                   1000.0
            << " us" << std::endl;
}
