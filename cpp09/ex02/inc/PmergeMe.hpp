#pragma once

#include <algorithm>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <vector>

template <typename Container>
void sort_fj(Container &container, std::size_t pair_size = 2) {
  const std::size_t n = container.size();

  if (n < 2) {
    return;
  }

  if (pair_size == 2) {
    for (std::size_t i = 0; i + 1 < n; i += 2) {
      if (container[i + 1] < container[i]) {
        std::swap(container[i], container[i + 1]);
      }
    }
  }

  const std::size_t block_size = pair_size * 2;

  if (block_size > n) {
    return;
  }

  for (std::size_t i = 0; i + block_size <= n; i += block_size) {
    std::size_t left_last_index = i + pair_size - 1;
    std::size_t right_last_index = i + block_size - 1;
    if (container[right_last_index] < container[left_last_index]) {
      for (std::size_t k = 0; k < pair_size; ++k) {
        std::swap(container[i + k], container[i + pair_size + k]);
      }
    }
  }

  sort_fj(container, block_size);
}

template <typename Container> Container parseAndLoad(int argc, char **argv) {
  Container container;

  for (int i = 1; i < argc; ++i) {
    int value = std::atoi(argv[i]);
    if (value < 0) {
      std::cerr << "Error: non-positive integer" << std::endl;
      exit(1);
    }

    container.push_back(value);
  }

  return container;
}

std::vector<int> sort_vector(int argc, char **argv);

std::deque<int> sort_deque(int argc, char **argv);
