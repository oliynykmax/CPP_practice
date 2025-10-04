#pragma once
#include "../inc/AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
  std::string _target;

public:
  PresidentialPardonForm() = delete;
  PresidentialPardonForm(std::string target);
  PresidentialPardonForm(PresidentialPardonForm const &src);
  ~PresidentialPardonForm() = default;

  PresidentialPardonForm &
  operator=(PresidentialPardonForm const &other) = delete;

  void execute(Bureaucrat const &executor) const;
};
