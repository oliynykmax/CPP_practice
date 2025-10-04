#pragma once
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
  std::string _target;

public:
  RobotomyRequestForm() = delete;
  RobotomyRequestForm(std::string target);
  RobotomyRequestForm(RobotomyRequestForm const &src);
  ~RobotomyRequestForm() = default;

  RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs) = delete;

  void execute(Bureaucrat const &executor) const;
};
