#include "../inc/PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &other)
    : AForm(other), _target(other._target) {}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
  AForm::validateExecution(executor);
  std::cout << _target << " has been pardoned by Zaphod Beeblebrox."
            << std::endl;
}
