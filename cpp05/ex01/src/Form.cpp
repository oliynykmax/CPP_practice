#include "../inc/Form.hpp"
#include <iostream>

Form::Form()
    : _name("Default form"), _gradeToSign(150), _gradeToExecute(150),
      _isSigned(false) {}

Form::~Form() {}

Form::Form(const Form &other)
    : _name(other._name), _gradeToSign(other._gradeToSign),
      _gradeToExecute(other._gradeToExecute), _isSigned(other._isSigned) {}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute),
      _isSigned(false) {
  if (gradeToSign < 1 || gradeToExecute < 1)
    throw GradeTooHighException(gradeToSign, gradeToExecute);
  else if (gradeToSign > 150 || gradeToExecute > 150)
    throw GradeTooLowException(gradeToSign, gradeToExecute);
}

int Form::getGradeToSign() const { return _gradeToSign; }
int Form::getGradeToExecute() const { return _gradeToExecute; }
bool Form::getStatus() const { return _isSigned; }
const std::string &Form::getName() const { return _name; }

void Form::beSigned(Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > _gradeToSign)
    throw GradeTooLowException(bureaucrat.getGrade(), _gradeToSign);
  _isSigned = true;
}

std::ostream &operator<<(std::ostream &os, Form const &Form) {
  os << Form.getName() << ", Form grade to sign: " << Form.getGradeToSign()
     << ", grade to execute: " << Form.getGradeToExecute()
     << " Status: " << (Form.getStatus() ? "true" : "false") << ".";
  return os;
}
