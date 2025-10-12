#pragma once
#include <string>

class ScalarConverter {
  ScalarConverter() = delete;
  ScalarConverter &operator=(ScalarConverter &other) = default;
  ScalarConverter(ScalarConverter &other) = default;
  ~ScalarConverter() = default;

public:
  static void convert(std::string input);
};
