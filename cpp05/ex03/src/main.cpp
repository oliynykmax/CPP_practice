#include "../inc/Bureaucrat.hpp"
#include "../inc/Intern.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
  std::srand(std::time(0));

  try {
    Bureaucrat alice("Alice", 1);

    ShrubberyCreationForm shrubbery("home");
    RobotomyRequestForm robotomy("Bender");
    PresidentialPardonForm pardon("Marvin");

    std::cout << "\n--- Testing ShrubberyCreationForm ---\n";
    alice.signForm(shrubbery);
    alice.executeForm(shrubbery);

    std::cout << "\n--- Testing RobotomyRequestForm ---\n";
    alice.signForm(robotomy);
    alice.executeForm(robotomy);
    alice.executeForm(robotomy);
    alice.executeForm(robotomy);
    alice.executeForm(robotomy);

    std::cout << "\n--- Testing PresidentialPardonForm ---\n";
    alice.signForm(pardon);
    alice.executeForm(pardon);

    std::cout << "\n--- Testing error: executing unsigned form ---\n";
    RobotomyRequestForm unsignedForm("HAL 9000");
    alice.executeForm(unsignedForm);

    std::cout << "\n--- Testing error: insufficient grade to execute ---\n";
    Bureaucrat lowGrade("Bob", 100);
    RobotomyRequestForm restrictedForm("Data");
    alice.signForm(restrictedForm); // Alice signs it first
    lowGrade.executeForm(
        restrictedForm); // Bob tries to execute but grade too low

    std::cout << "\n--- Testing Intern makeForm ---\n";
    Intern someRandomIntern;
    AForm *f1 = NULL;
    AForm *f2 = NULL;
    AForm *f3 = NULL;

    try {
      f1 = someRandomIntern.makeForm("shrubbery creation", "park");
      alice.signForm(*f1);
      alice.executeForm(*f1);
    } catch (const std::exception &e) {
      std::cout << "Intern makeForm shrubbery error: " << e.what() << std::endl;
    }

    try {
      f2 = someRandomIntern.makeForm("robotomy request", "Bender");
      alice.signForm(*f2);
      alice.executeForm(*f2);
    } catch (const std::exception &e) {
      std::cout << "Intern makeForm robotomy error: " << e.what() << std::endl;
    }

    try {
      f3 = someRandomIntern.makeForm("presidential pardon", "Marvin");
      alice.signForm(*f3);
      alice.executeForm(*f3);
    } catch (const std::exception &e) {
      std::cout << "Intern makeForm pardon error: " << e.what() << std::endl;
    }

    try {
      someRandomIntern.makeForm("unknown form", "Target");
    } catch (const std::exception &e) {
      std::cout << "Intern unknown form error: " << e.what() << std::endl;
    }

    delete f1;
    delete f2;
    delete f3;

  } catch (const std::exception &e) {
    std::cerr << "Exception caught in main: " << e.what() << std::endl;
  }

  return 0;
}
