#include <algorithm>
#include <bit>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

size_t jacobsthal(size_t n) {
  size_t power = 1 << (n + 1);
  int sign = (n % 2 == 0) ? 1 : -1;
  return (power + sign) / 3;
}
// size_t jacobstahl(size_t n)
// {
//     return (4 << n) / 3 + ((n + 1) % 2);
// }
template <typename T> T pair(T &c, long e_size) {
  if (e_size * 2 > c.size())
    return c;
  for (auto i = e_size - 1; (i + e_size < c.size()); i = i + e_size * 2) {
    if (c[i] > c[i + e_size]) {
      for (long j = i; j > i - e_size; j--) {
        std::swap(c[j], c[j + e_size]);
      }
    }
  }
  return pair(c, e_size * 2);
}

int main() {
  std::vector<int> vec = {11, 2,  17, 0,  16, 8,  6, 15, 10, 3,  21,
                          1,  18, 9,  14, 19, 12, 5, 4,  20, 13, 7};
  std::vector<int> vect = pair(vec, 1);
  long biggest = std::bit_floor(vec.size()) / 2;
  for (size_t i = 0; i < vect.size(); i++) {
    std::cout << vect[i] << " ";
  }
    std::cout << std::endl;
  while (biggest > 0) {
      for (size_t i = 2; i < vect.size() / biggest; i++) {
          size_t j      = i * biggest;
          size_t mid_idx = ((i - 1) * 2 + 1) * biggest;
          size_t end_idx = ((i - 1) * 2 + 2) * biggest;

          if (j < vect.size()) {
              auto first  = vect.begin() + j;
              auto middle = vect.begin() + std::min(mid_idx, vect.size());
              auto last   = vect.begin() + std::min(end_idx, vect.size());

              if (first < middle && middle < last) {
                  std::rotate(first, middle, last);
              }
          }
      }
      if (biggest == 4) {
          break;
      }
      biggest /= 2;
  }

  for (size_t i = 0; i < vect.size(); i++) {
    std::cout << vect[i] << " ";
  }
}
