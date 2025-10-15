#pragma once
#include <exception>
#include <iostream>
#include <stdexcept>
#include <utility>

template <typename T> class Array {
public:
  Array() : data(nullptr), size_array(0) {}
  Array(unsigned n) : data(n ? new T[n]() : nullptr), size_array(n) {}
  ~Array() { delete[] data; }

  Array(const Array &other)
      : data(other.size_array ? new T[other.size_array] : nullptr),
        size_array(other.size_array) {
    for (size_t i = 0; i < size_array; ++i)
      data[i] = other.data[i];
  }

  Array &operator=(Array other) {
    std::swap(data, other.data);
    std::swap(size_array, other.size_array);
    return *this;
  }

  T &operator[](size_t index) {
    if (index >= size_array)
      throw std::exception();
    return data[index];
  }

  T const &operator[](size_t index) const {
    if (index >= size_array)
      throw std::exception();
    return data[index];
  }

  size_t size() const { return size_array; }

private:
  T *data;
  size_t size_array;
};
