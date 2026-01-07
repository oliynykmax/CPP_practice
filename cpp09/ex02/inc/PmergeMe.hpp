#pragma once
#include <algorithm>
#include <bit>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <vector>

size_t jacobsthal(size_t n);

template <typename T> void pair(T &c, long e_size) {
  if (e_size * 2 > (long)c.size())
    return;
  for (auto i = e_size - 1; (i + e_size < (long)c.size()); i = i + e_size * 2) {
    if (c[i] > c[i + e_size]) {
      for (long j = i; j > i - e_size; j--) {
        std::swap(c[j], c[j + e_size]);
      }
    }
  }
  pair(c, e_size * 2);
}

template <typename T> void ford_johnson_sort(T &c) {
  pair(c, 1);

  long biggest = std::bit_floor(c.size()) / 2;

  while (biggest > 0) {
    for (size_t i = 2, j = 3; j * biggest + biggest <= c.size(); i++, j += 2) {
      std::rotate(c.begin() + i * biggest, c.begin() + j * biggest,
                  c.begin() + j * biggest + biggest);
    }

    size_t n_pairs = c.size() / biggest / 2;
    size_t pend_total = c.size() / biggest - (n_pairs + 1);
    size_t jacob = 3;
    size_t prev = 1;
    size_t inserted = 0;

    while (inserted < pend_total) {
      auto J = std::min(jacobsthal(jacob++), pend_total + 1);

      size_t source = n_pairs + (J - 1);

      for (size_t k = J; k > prev; --k) {
        size_t bound = inserted + ((k <= n_pairs) ? k : n_pairs + 1);

        int val = c[source * biggest + biggest - 1];
        long l = 0;
        while (l < (long)bound) {
          long mid = l + (bound - l) / 2;
          if (c[mid * biggest + biggest - 1] < val)
            l = mid + 1;
          else
            bound = mid;
        }

        std::rotate(c.begin() + l * biggest, c.begin() + source * biggest,
                    c.begin() + (source + 1) * biggest);
        inserted++;
      }
      prev = J;
    }

    biggest /= 2;
  }
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
