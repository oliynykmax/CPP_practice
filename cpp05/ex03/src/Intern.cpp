#include "../inc/Intern.hpp"

#include "../inc/AForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

#include <algorithm>
#include <cctype>
#include <iostream>

static std::string toLower(std::string s) {
  std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {
    return static_cast<char>(std::tolower(c));
  });
  return s;
}

// Factory functions for each known form type
static AForm *createShrubbery(const std::string &target) {
  return new ShrubberyCreationForm(target);
}

static AForm *createRobotomy(const std::string &target) {
  return new RobotomyRequestForm(target);
}

static AForm *createPresidential(const std::string &target) {
  return new PresidentialPardonForm(target);
}

struct FormSpec {
  const char *name; // canonical lowercase name
  AForm *(*creator)(const std::string &);
};

static const FormSpec kFormTable[] = {
    {"shrubbery creation", &createShrubbery},
    {"robotomy request", &createRobotomy},
    {"presidential pardon", &createPresidential},
};

AForm *Intern::makeForm(const std::string &formName,
                        const std::string &target) const {
  for (const FormSpec &spec : kFormTable) {
    if (toLower(formName) == spec.name) {
      AForm *form = spec.creator(target);
      std::cout << "Intern creates " << formName << std::endl;
      return form;
    }
  }

  std::cerr << "Intern cannot create unknown form: '" << formName << "'"
            << std::endl;
  throw UnknownFormException(formName);
}
