#pragma once
#include "Data.hpp"
#include <cstdint>

class Serializer {
private:
  Serializer() = delete;
  ~Serializer() = delete;
  Serializer(const Serializer &other) = delete;
  Serializer &operator=(const Serializer &other) = delete;

public:
  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);
};
