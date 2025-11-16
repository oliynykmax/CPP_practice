#include "../inc/PmergeMe.hpp"
#include <cmath>

size_t jacobsthal(size_t n) {
  size_t power = 1 << (n + 1);
  int sign = (n % 2 == 0) ? 1 : -1;
  return (power + sign) / 3;
}

std::vector<int> sort_vector(int argc, char **argv) {
  std::vector<int> vec = parseAndLoad<std::vector<int>>(argc, argv);
  return ford_johnson_sort(vec);
}

std::deque<int> sort_deque(int argc, char **argv) {
  std::deque<int> deq = parseAndLoad<std::deque<int>>(argc, argv);
  return ford_johnson_sort(deq);
}
