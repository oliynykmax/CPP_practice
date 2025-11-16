#pragma once

#include <algorithm>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <vector>

size_t jacobsthal(size_t n);

template <typename Container>
void pair_sort(Container &c, std::size_t pair_size = 2) {}

template <typename Container>
void build_main(const Container &c, Container &main, Container &pend) {
  const size_t n = c.size();
  const size_t num_pairs = n / 2;
  const bool has_straggler = (n % 2 == 1);
  if (num_pairs == 0) {
    if (n == 1)
      main.push_back(c[0]);
    return;
  }
  main.push_back(c[0]);
  for (size_t i = 0; i < num_pairs; ++i) {
    main.push_back(c[2 * i + 1]);
  }
  for (size_t i = 1; i < num_pairs; ++i) {
    pend.push_back(c[2 * i]);
  }
  if (has_straggler) {
    pend.push_back(c[n - 1]);
  }
}

template <typename Container> void insertion(Container &main, Container &pend) {
  if (pend.empty())
    return;
  size_t pend_size = pend.size();
  std::vector<size_t> jacobsthal_seq;
  size_t jacob_idx = 3;
  while (jacobsthal(jacob_idx) <= pend_size + 1) {
    jacobsthal_seq.push_back(jacobsthal(jacob_idx));
    jacob_idx++;
  }
  std::vector<bool> inserted(pend_size, false);
  size_t prev_jacob = 1;
  for (size_t jacob : jacobsthal_seq) {
    for (size_t b_idx = jacob; b_idx > prev_jacob; --b_idx) {
      if (b_idx < 2)
        continue;
      size_t pend_idx = b_idx - 2;
      if (pend_idx >= pend_size)
        continue;
      if (inserted[pend_idx])
        continue;
      size_t limit = b_idx;
      for (size_t i = 0; i < pend_size; ++i) {
        if (inserted[i])
          limit++;
      }
      limit = std::min(limit, main.size());

      auto pos =
          std::upper_bound(main.begin(), main.begin() + limit, pend[pend_idx]);
      main.insert(pos, pend[pend_idx]);
      inserted[pend_idx] = true;
    }
    prev_jacob = jacob;
  }

  for (int pend_idx = pend_size - 1; pend_idx >= 0; --pend_idx) {
    if (inserted[pend_idx])
      continue;

    size_t b_idx = pend_idx + 2;
    size_t limit = b_idx;
    for (size_t i = 0; i < pend_size; ++i) {
      if (inserted[i])
        limit++;
    }
    limit = std::min(limit, main.size());

    auto pos =
        std::upper_bound(main.begin(), main.begin() + limit, pend[pend_idx]);
    main.insert(pos, pend[pend_idx]);
    inserted[pend_idx] = true;
  }
}

template <typename Container> Container ford_johnson_sort(Container &c) {
  const size_t n = c.size();

  if (n <= 1)
    return c;

  pair_sort(c);

  Container main, pend;
  build_main(c, main, pend);

  insertion(main, pend);

  return main;
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
