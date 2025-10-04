#include "../inc/Bureaucrat.hpp"
#include <iostream>

int main() {
  try {
    Bureaucrat bureaucrat("John", 1);
    std::cout << bureaucrat << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    Bureaucrat bureaucrat("Lock", 0);
    std::cout << bureaucrat << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    Bureaucrat bureaucrat("Dummy", 151);
    std::cout << bureaucrat << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    Bureaucrat bureaucrat("Mike", 50);
    std::cout << bureaucrat << std::endl;
    bureaucrat.incrementGrade(500);
    std::cout << bureaucrat << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    Bureaucrat bureaucrat("Mike", 50);
    std::cout << bureaucrat << std::endl;
    bureaucrat.decrementGrade(2147483647);
    std::cout << bureaucrat << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    Bureaucrat bureaucrat{};
    std::cout << bureaucrat << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}
