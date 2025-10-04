#pragma once

#include <exception>
#include <string>

class AForm;

class Intern {
public:
  Intern() = default;
  Intern(const Intern &other) = default;
  Intern &operator=(const Intern &other) = default;
  ~Intern() = default;
  AForm *makeForm(const std::string &formName, const std::string &target) const;
  class UnknownFormException : public std::exception {
  private:
    std::string _msg;

  public:
    explicit UnknownFormException(const std::string &name)
        : _msg("Unknown form name: '" + name + "'") {}
    const char *what() const noexcept override { return _msg.c_str(); }
  };
};
