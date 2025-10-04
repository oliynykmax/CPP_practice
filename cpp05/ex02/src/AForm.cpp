#include "../inc/AForm.hpp"
#include <iostream>

AForm::AForm()
    : _name("Default form"), _gradeToSign(150), _gradeToExecute(150),
      _isSigned(false) {}

AForm::~AForm() {}

AForm::AForm(const AForm &other)
    : _name(other._name), _gradeToSign(other._gradeToSign),
      _gradeToExecute(other._gradeToExecute), _isSigned(other._isSigned) {}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute),
      _isSigned(false) {
  if (gradeToSign < 1 || gradeToExecute < 1)
    throw GradeTooHighException(gradeToSign, gradeToExecute);
  else if (gradeToSign > 150 || gradeToExecute > 150)
    throw GradeTooLowException(gradeToSign, gradeToExecute);
}

int AForm::getGradeToSign() const { return _gradeToSign; }
int AForm::getGradeToExecute() const { return _gradeToExecute; }
bool AForm::getStatus() const { return _isSigned; }
const std::string &AForm::getName() const { return _name; }

void AForm::beSigned(Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > _gradeToSign)
    throw GradeTooLowException(bureaucrat.getGrade(), _gradeToSign);
  _isSigned = true;
}

std::ostream &operator<<(std::ostream &os, AForm const &Form) {
  os << Form.getName() << ", Form grade to sign: " << Form.getGradeToSign()
     << ", grade to execute: " << Form.getGradeToExecute()
     << " Status: " << (Form.getStatus() ? "true" : "false") << ".";
  return os;
}

void AForm::validateExecution(Bureaucrat const &executor) const {
  if (!_isSigned)
    throw std::runtime_error("Form is not signed");
  if (executor.getGrade() > _gradeToExecute)
    throw GradeTooLowException(executor.getGrade(), _gradeToExecute);
}
