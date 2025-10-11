#include "../inc/ScalarConverter.hpp"
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <regex>
#include <sstream>
#include <stdexcept>
#include <string>

static const std::regex &doubleRegex() {
  static const std::regex re(
      R"(^[+-]?(?:\d*\.\d+|\d+\.\d*|\d+)(?:[eE][+-]?\d+)?$)",
      std::regex::optimize);
  return re;
}

static const std::regex &floatRegex() {
  static const std::regex re(
      R"(^[+-]?(?:\d*\.\d+|\d+\.\d*|\d+)(?:[eE][+-]?\d+)?[fF]$)",
      std::regex::optimize);
  return re;
}

static bool isDouble(const std::string &s) {
  return std::regex_match(s, doubleRegex());
}

static bool isFloat(const std::string &s) {
  return std::regex_match(s, floatRegex());
}

static bool isInteger(const std::string &s) {
  if (s.empty())
    return false;
  size_t i = 0;
  if (s[0] == '-' || s[0] == '+') {
    if (s.size() == 1)
      return false;
    i = 1;
  }
  for (; i < s.size(); ++i) {
    if (!std::isdigit(static_cast<unsigned char>(s[i])))
      return false;
  }
  return true;
}

static std::string formatFloat(float value) {
  if (std::isnan(value))
    return std::string("nan");
  if (std::isinf(value))
    return value > 0 ? std::string("+inf") : std::string("-inf");
  if (std::isfinite(value) && std::floor(value) == value) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(1) << value;
    return oss.str();
  }
  std::ostringstream oss;
  oss << std::defaultfloat << value;
  return oss.str();
}

static std::string formatDouble(double value) {
  if (std::isnan(value))
    return std::string("nan");
  if (std::isinf(value))
    return value > 0 ? std::string("+inf") : std::string("-inf");
  if (std::isfinite(value) && std::floor(value) == value) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(1) << value;
    return oss.str();
  }
  std::ostringstream oss;
  oss << std::defaultfloat << value;
  return oss.str();
}

static void print_converted(std::string n, double d, float f) {
  if (std::isnan(d) || d > 127 || d < 0) {
    std::cout << "char: " << "impossible" << std::endl;
  } else {
    char c = static_cast<char>(d);
    if (std::isprint(static_cast<unsigned char>(c))) {
      std::cout << "char: '" << c << "'" << std::endl;
    } else {
      std::cout << "char: Non displayable" << std::endl;
    }
  }
  if (n.empty())
    std::cout << "int: " << static_cast<int>(d) << std::endl;
  else
    std::cout << "int: " << n << std::endl;
  std::cout << "float: " << formatFloat(f) << "f" << std::endl;
  std::cout << "double: " << formatDouble(d) << std::endl;
}

void ScalarConverter::convert(std::string input) {
  if (input == "nan" || input == "nanf") {
    print_converted("impossible", NAN, NAN);
    return;
  } else if (input == "+inf" || input == "+inff") {
    print_converted("impossible", INFINITY, INFINITY);
    return;
  } else if (input == "-inf" || input == "-inff") {
    print_converted("impossible", -INFINITY, -INFINITY);
    return;
  }

  float f = 0.0f;
  double d = 0.0;

  if (isInteger(input) || isFloat(input) || isDouble(input)) {
    try {
      f = std::stof(input);
    } catch (const std::out_of_range &) {
      f = (input[0] == '-') ? -std::numeric_limits<float>::infinity()
                            : std::numeric_limits<float>::infinity();
    }
    try {
      d = std::stod(input);
    } catch (const std::out_of_range &) {
      d = (input[0] == '-') ? -std::numeric_limits<double>::infinity()
                            : std::numeric_limits<double>::infinity();
    }
    std::string str = "";
    if (d > std::numeric_limits<int>::max() ||
        d < std::numeric_limits<int>::min()) {
      str = "impossible";
    }
    print_converted(str, d, f);
  } else if (input.size() == 1) {
    char c = input[0];
    print_converted("", c, c);
  } else {
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    std::cout << "float: impossible\n";
    std::cout << "double: impossible\n";
  }
}
