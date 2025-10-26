#include "../inc/PmergeMe.hpp"

std::vector<int> sort_vector(int argc, char **argv) {
  std::vector<int> vec = parseAndLoad<std::vector<int>>(argc, argv);

  std::sort(vec.begin(), vec.end());
  return vec;
}

std::deque<int> sort_deque(int argc, char **argv) {
  std::deque<int> deq = parseAndLoad<std::deque<int>>(argc, argv);

  std::sort(deq.begin(), deq.end());
  return deq;
}
