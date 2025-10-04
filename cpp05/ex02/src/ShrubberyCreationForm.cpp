#include "../inc/ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), _target(other._target) {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  AForm::validateExecution(executor);
  std::fstream file(_target + "_shrubbery", std::ios::out);
  if (!file.is_open()) {
    throw std::runtime_error("Failed to open file");
  }
  file << "       _-_" << std::endl;
  file << "    /~~   ~~\\" << std::endl;
  file << " /~~         ~~\\" << std::endl;
  file << "{               }" << std::endl;
  file << " \\  _-     -_  /" << std::endl;
  file << "   ~  \\ //  ~" << std::endl;
  file << "_- -   | | _- _" << std::endl;
  file << "  _ -  | |   -_" << std::endl;
  file << "      // \\\\" << std::endl;
  file.close();
}
