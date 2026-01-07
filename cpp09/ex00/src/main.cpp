#include "../inc/BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv) {
  (void)argv;
  if (argc != 2) {
    std::cerr << "Error: could not open file." << std::endl;
    return 1;
  }
  try {
    BitcoinExchange db;
    db.processFile(argv[1]);
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  return 0;
}
