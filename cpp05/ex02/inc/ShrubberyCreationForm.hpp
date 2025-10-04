#pragma once
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
private:
  std::string _target;

public:
  ShrubberyCreationForm() = default;
  ShrubberyCreationForm(std::string target);
  ShrubberyCreationForm(ShrubberyCreationForm const &src);
  ~ShrubberyCreationForm() = default;

  ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other) = delete;

  void execute(Bureaucrat const &executor) const;
};
