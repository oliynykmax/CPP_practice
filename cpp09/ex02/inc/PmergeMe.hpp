#pragma once
#include <algorithm>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <vector>

size_t jacobsthal(size_t n);



template <typename T> T pair(T &c, size_t p_size) {
    if (p_size > c.size()) return c;
    for (auto i = c.size() - 1; i < c.size(); i = i + p_size * 2) {
        if (i + p_size > c.size()) break;
        if (c[i] > c[i + p_size]) {
            auto j = i;
            while (j > i - p_size) {
                std::swap(c[j], c[j + p_size]);
                j--;
            }
        }
    }
    return pair(c, p_size * 2)
}

template <typename T> T ford_johnson_sort(T &c) {

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

cursor parking lot:
-
-

  9 5 7 4 3 6 8 1 2
  [9 5] [7 4] [3 6] [8 1] 2
  [5 9] [4 7] [3 6] [1 8] 2

  [[4 7] [5 9]] [[3 6] [1 8]] 2

  [[[3 6] [1 8]] [[4 7] [5 9]]] 2



  1 2 3 4 5 6 7
  1 2 3 4
