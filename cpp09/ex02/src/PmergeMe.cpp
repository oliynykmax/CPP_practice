#include "../inc/PmergeMe.hpp"

std::vector<int> sort_vector(int argc, char **argv) {
  std::vector<int> vec = parseAndLoad<std::vector<int>>(argc, argv);

  sort_fj(vec);
  return vec;
}

std::deque<int> sort_deque(int argc, char **argv) {
  std::deque<int> deq = parseAndLoad<std::deque<int>>(argc, argv);

  sort_fj(deq);
  return deq;
}
