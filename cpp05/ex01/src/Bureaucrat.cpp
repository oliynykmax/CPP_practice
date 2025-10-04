#include "../inc/Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
  std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() {
  std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : _name(other._name), _grade(other._grade) {
  std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
  std::cout << "Bureaucrat copy assignment operator called" << std::endl;
  if (this != &other) {
    _grade = other._grade;
  }
  return *this;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
    : _name(name), _grade(grade) {
  std::cout << "Bureaucrat constructor called" << std::endl;
  if (grade < 1)
    throw GradeTooHighException(grade);
  else if (grade > 150)
    throw GradeTooLowException(grade);
}

int Bureaucrat::getGrade() const { return _grade; }

const std::string &Bureaucrat::getName() const { return _name; }

void Bureaucrat::incrementGrade(int amount) {
  if (amount > _grade - 1) {
    throw GradeTooHighException(amount);
  } else {
    _grade -= amount;
  }
}

void Bureaucrat::decrementGrade(int amount) {
  if (amount > 150 - _grade) {
    throw GradeTooLowException(amount);
  } else {
    _grade += amount;
  }
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat) {
  os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade()
     << ".";
  return os;
}

void Bureaucrat::signForm(Form &form) {
  try {
    form.beSigned(*this);
    std::cout << _name << " signed " << form.getName() << std::endl;
  } catch (const Form::GradeTooLowException &e) {
    std::cout << _name << " couldn't sign " << form.getName()
              << " because grade " << _grade
              << " is too low (required: " << form.getGradeToSign() << ")"
              << std::endl;
  }
}
