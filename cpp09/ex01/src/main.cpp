#include "../inc/RPN.hpp"
#include <exception>
#include <iostream>

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " \"<expression>\"" << std::endl;
    return 1;
  }
  try {
    std::cout << rpn_calculate(argv[1]) << std::endl;
  } catch (const std::exception &e) {
    return 1;
  }
  return (0);
}
