#pragma once
#include <string>

class ScalarConverter {
    public:
  ScalarConverter() = delete;
  ScalarConverter &operator=(ScalarConverter &other) = default;
  ScalarConverter(ScalarConverter &other) = default;
  ~ScalarConverter() = default;

  static void convert(std::string input);
};
