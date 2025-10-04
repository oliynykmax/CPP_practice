#include "../inc/Bureaucrat.hpp"
#include <iostream>

int main() {
  try {
    Bureaucrat bureaucrat("John", 2);
    std::cout << bureaucrat << std::endl;
    Form form("Form1", 1, 1);
    bureaucrat.signForm(form);
    std::cout << form << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  try {
    Form formTooHigh("Form2", 234, 0);
    std::cout << formTooHigh << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  try {
    Form form2("Form2", 2, 1);
    std::cout << form2 << std::endl;
    Bureaucrat bureaucrat("John", 1);
    bureaucrat.signForm(form2);
    std::cout << form2 << std::endl;
    Form form_copy(form2);
    Form form_copy2(form_copy);
    std::cout << form_copy << std::endl;
    std::cout << form_copy2 << std::endl;
    Form form_plain;
    std::cout << form_plain << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  try {
    Bureaucrat bureaucrat("Dummy", 150);
    Form form("Form3", 1, 1);
    bureaucrat.signForm(form);
    std::cout << bureaucrat << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}
