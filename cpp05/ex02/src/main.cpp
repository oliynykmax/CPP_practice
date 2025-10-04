#include "../inc/Bureaucrat.hpp"
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

  } catch (const std::exception &e) {
    std::cerr << "Exception caught in main: " << e.what() << std::endl;
  }

  return 0;
}
