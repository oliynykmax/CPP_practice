#include "../inc/ScalarConverter.hpp"
#include <iostream>
#include <string>

int main(int argc, char **argv) {
  if (argc > 1) {
    for (int i = 1; i < argc; ++i)
      ScalarConverter::convert(argv[i]);
    return 0;
  }
  const char *tests[] = {"a",
                         " ",
                         "0",
                         "42",
                         "-42",
                         "+42",
                         "2147483647",
                         "-2147483648",
                         "2147483648",
                         "-2147483649",
                         "0.0f",
                         "42.0f",
                         "3.14f",
                         ".5f",
                         "123.f",
                         "1e10f",
                         "-1e-10f",
                         "3.4028235e38f",
                         "1.17549435e-38f",
                         "1e39f",
                         "-1e39f",
                         "nanf",
                         "+inff",
                         "-inff",
                         "0.0",
                         "42.0",
                         "3.14",
                         ".5",
                         "123.",
                         "1e10",
                         "-1e-10",
                         "1e-20",
                         "1e-300",
                         "2.2250738585072014e-308",
                         "1.7976931348623157e308",
                         "1e309",
                         "-1e309",
                         "nan",
                         "+inf",
                         "-inf",
                         "1e-10",
                         "abc",
                         "1.2.3",
                         "f",
                         ".",
                         "++1",
                         "--2",
                         "-",
                         "+",
                         "infz"};
  for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); ++i) {
    std::cout << tests[i] << std::endl << std::endl;
    ScalarConverter::convert(tests[i]);
    std::cout << std::endl;
  }
  return 0;
}
