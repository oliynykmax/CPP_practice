#include "PhoneBook.hpp"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <climits>
#include <cctype>

PhoneBook::PhoneBook() : currentIndex(0), totalContacts(0) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::addContact() {
    Contact contact;
    std::string input;

    while (true) {
        std::cout << "Enter first name: ";
        std::getline(std::cin >> std::ws, input);
        if (!input.empty()) {
            contact.setFirstName(input);
            break;
        }
        std::cout << "\033[31mError: Field cannot be empty!\033[0m\n";
    }

    while (true) {
        std::cout << "Enter last name: ";
        std::getline(std::cin, input);
        if (!input.empty()) {
            contact.setLastName(input);
            break;
        }
        std::cout << "\033[31mError: Field cannot be empty!\033[0m\n";
    }

    while (true) {
        std::cout << "Enter nickname: ";
        std::getline(std::cin, input);
        if (!input.empty()) {
            contact.setNickname(input);
            break;
        }
        std::cout << "\033[31mError: Field cannot be empty!\033[0m\n";
    }

    while (true) {
        std::cout << "Enter phone number: ";
        std::getline(std::cin, input);
        bool valid = true;
        for (size_t i = 0; i < input.length(); i++) {
            if (!isdigit(input[i])) {
                std::cout << "\033[31mPhone number must contain only digits!\033[0m\n";
                valid = false;
                break;
            }
        }
        if (!valid) {
            continue;
        }

        if (input.empty()) {
            std::cout << "\033[31mPhone number cannot be empty!\033[0m\n";
            continue;
        }
        contact.setPhoneNumber(input);
        break;
    }


    while (true) {
        std::cout << "Enter darkest secret: ";
        std::getline(std::cin, input);
        if (!input.empty()) {
            contact.setDarkestSecret(input);
            break;
        }
        std::cout << "\033[31mError: Field cannot be empty!\033[0m\n";
    }


    _contacts[currentIndex] = contact;
    currentIndex = (currentIndex + 1) % 8;
    if (totalContacts < 8) {
        totalContacts++;
    }
    std::cout << "Contact added successfully!\n" << std::endl;
}

void PhoneBook::searchContacts() const {
    if (totalContacts == 0) {
        std::cout << "No contacts found!\n";
        return;
    }
    std::cout << "┌──────────┬──────────┬──────────┬──────────┐\n"
              << "│" << std::setw(10) << std::right << "Index" << "│"
              << std::setw(10) << std::right << "Name" << "│"
              << std::setw(10) << std::right << "Surname" << "│"
              << std::setw(10) << std::right << "Nickname" << "│\n"
              << "├──────────┼──────────┼──────────┼──────────┤\n";

    // Contacts
    for (int i = 0; i < totalContacts; ++i) {
        const Contact& c = _contacts[i];
        std::cout << "│" << std::setw(10) << std::right << i + 1<< "│"
                  << std::setw(10) << std::right << _truncate(c.getFirstName()) << "│"
                  << std::setw(10) << std::right << _truncate(c.getLastName()) << "│"
                  << std::setw(10) << std::right << _truncate(c.getNickName()) << "│\n";
    }
    std::cout << "└──────────┴──────────┴──────────┴──────────┘\n";
    std::string input;
    int idx;
    while (true) {
        std::cout << "Enter index to display: ";
        std::getline(std::cin >> std::ws, input);
        
        // Check if input is empty
        if (input.empty()) {
            std::cout << "\033[31mError: Input cannot be empty!\033[0m\n";
            continue;
        }
        
        // Check if input contains only digits
        bool isValidNumber = true;
        for (size_t i = 0; i < input.length(); i++) {
            if (!std::isdigit(input[i])) {
                std::cout << "\033[31mError: Please enter only numbers!\033[0m\n";
                isValidNumber = false;
                break;
            }
        }
        if (!isValidNumber) {
            continue;
        }
        
        // Check for overflow - simple approach without exceptions
        if (input.length() > 10) {
            std::cout << "\033[31mError: Number too large! Please enter a smaller number.\033[0m\n";
            continue;
        }
        
        // Convert string to int manually to avoid overflow
        long long temp = 0;
        for (size_t i = 0; i < input.length(); i++) {
            temp = temp * 10 + (input[i] - '0');
            if (temp > INT_MAX) {
                std::cout << "\033[31mError: Number too large! Please enter a smaller number.\033[0m\n";
                isValidNumber = false;
                break;
            }
        }
        if (!isValidNumber) {
            continue;
        }
        
        idx = static_cast<int>(temp);
        
        // Check if index is in valid range
        if (idx < 1 || idx > totalContacts) {
            std::cout << "\033[31mError: Index must be between 1 and " << totalContacts << "!\033[0m\n";
            continue;
        }
        
        break;
    }

    displayContact(idx);
}

std::string PhoneBook::_truncate(const std::string& str) const {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void PhoneBook::displayContact(int index) const {
    index = index - 1;
    if (index >= 0 && index < totalContacts) {
        std::cout << "First Name: " << _contacts[index].getFirstName() << std::endl;
        std::cout << "Last Name: " << _contacts[index].getLastName() << std::endl;
        std::cout << "Nickname: " << _contacts[index].getNickName() << std::endl;
        std::cout << "Phone Number: " << _contacts[index].getPhoneNumber() << std::endl;
        std::cout << "Darkest Secret: " << _contacts[index].getDarkestSecret() << std::endl;
    } else {
        std::cout << "Invalid contact index." << std::endl;
    }
}
