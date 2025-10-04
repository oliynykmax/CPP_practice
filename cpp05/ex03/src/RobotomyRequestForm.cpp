#include "../inc/RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(std::string _target)
    : AForm("RobotomyRequestForm", 72, 45), _target(_target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), _target(other._target) {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
  AForm::validateExecution(executor);
  std::cout << "BZZZZZT! Drilling noises..." << std::endl;

  if (std::rand() % 2 == 0) {
    std::cout << _target << " has been robotomized successfully!" << std::endl;
  } else {
    std::cout << "Robotomy failed for " << _target << "." << std::endl;
  }
}
