#pragma once

#include <algorithm>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <vector>

template <typename Container> Container parseAndLoad(int argc, char **argv) {
  Container container;

  for (int i = 1; i < argc; ++i) {
    int value = std::atoi(argv[i]);
    if (value <= 0) {
      std::cerr << "Error: non-positive integer" << std::endl;
      exit(1);
    }

    if (std::find(container.begin(), container.end(), value) !=
        container.end()) {
      std::cerr << "Error: duplicated integer" << std::endl;
      exit(1);
    }

    container.push_back(value);
  }

  return container;
}

std::vector<int> sort_vector(int argc, char **argv);

std::deque<int> sort_deque(int argc, char **argv);
