#pragma once
#include "Bureaucrat.hpp"
#include <exception>
#include <string>

class Bureaucrat;

class Form {
private:
  const std::string _name;
  const int _gradeToSign;    // grade required to sign the form
  const int _gradeToExecute; // grade required to execute the form
  bool _isSigned;

public:
  Form();
  Form(const std::string &name, int gradeToSign, int gradeToExecute);
  Form(Form const &other);
  Form &operator=(Form const &other) = delete;
  ~Form();

  const std::string &getName() const;
  bool getStatus() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;

  void beSigned(Bureaucrat &bureaucrat);

  class GradeTooHighException : public std::exception {
  private:
    std::string _msg;

  public:
    GradeTooHighException(int num, int num2)
        : _msg("Grade too high - sign grade: " + std::to_string(num) +
               ", execute grade: " + std::to_string(num2)) {}

    const char *what() const noexcept override { return _msg.c_str(); }
  };

  class GradeTooLowException : public std::exception {
  private:
    std::string _msg;

  public:
    GradeTooLowException(int num, int num2)
        : _msg("Grade too low - sign grade: " + std::to_string(num) +
               ", execute grade: " + std::to_string(num2)) {}

    const char *what() const noexcept override { return _msg.c_str(); }
  };
};

std::ostream &operator<<(std::ostream &os, Form const &Form);
