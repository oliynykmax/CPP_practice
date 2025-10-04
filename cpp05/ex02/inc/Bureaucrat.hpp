#pragma once
#include "AForm.hpp"
#include <exception>
#include <string>

class AForm;

class Bureaucrat {
private:
  const std::string _name;
  int _grade; // 1 is highest, 150 is lowest

public:
  Bureaucrat();
  Bureaucrat(const std::string &name, int grade);
  Bureaucrat(Bureaucrat const &other);
  Bureaucrat &operator=(Bureaucrat const &other);
  ~Bureaucrat();

  const std::string &getName() const;
  int getGrade() const;
  void incrementGrade(int amount = 1);
  void decrementGrade(int amount = 1);
  void signForm(AForm &form);
  void executeForm(AForm const &form);
  class GradeTooHighException : public std::exception {
  private:
    std::string _msg;

  public:
    GradeTooHighException(int num)
        : _msg("Grade too high, amount tried: " + std::to_string(num)) {}

    const char *what() const noexcept override { return _msg.c_str(); }
  };

  class GradeTooLowException : public std::exception {
  private:
    std::string _msg;

  public:
    GradeTooLowException(int num)
        : _msg("Grade too low, amount tried: " + std::to_string(num)) {}

    const char *what() const noexcept override { return _msg.c_str(); }
  };
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat);
