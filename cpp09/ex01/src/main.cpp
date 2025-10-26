#include "../inc/RPN.hpp"
#include <iostream>

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " \"<expression>\"" << std::endl;
    return 1;
  }
  std::cout << rpn_calculate(argv[1]) << std::endl;
}
