#pragma once

#include <algorithm>
#include <stdexcept>

template <typename T> typename T::iterator easyfind(T &container, int n) {
  auto it = std::find(container.begin(), container.end(), n);
  if (it == container.end())
    throw std::runtime_error("Value not found");
  return it;
}

template <typename T>
typename T::const_iterator easyfind(const T &container, int n) {
  auto it = std::find(container.begin(), container.end(), n);
  if (it == container.end())
    throw std::runtime_error("Value not found");
  return it;
}
