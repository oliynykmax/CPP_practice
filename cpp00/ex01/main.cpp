#include "PhoneBook.hpp"
#include <iostream>
#define COLOR_RESET   "\033[0m"
#define COLOR_RED     "\033[31m"
#define COLOR_GREEN   "\033[32m"
#define COLOR_YELLOW  "\033[33m"
#define COLOR_BLUE    "\033[34m"
#define COLOR_MAGENTA "\033[35m"
#define COLOR_CYAN    "\033[36m"
#define COLOR_WHITE   "\033[37m"

int main() {
    PhoneBook book;
    std::string cmd;

    std::cout << COLOR_YELLOW << "Welcome to the awesome phone book!\n"
                 "Here you can add all 8 contacts with some details (likely)\n"
                 "and then check that information later\n"
                 "Available commands are ADD, SEARCH and EXIT" << std::endl;
    while (true) {
        std::cout << COLOR_RESET<<  "> ";
        if (!std::getline(std::cin, cmd)) {
            std::cout << "\nExiting..." << std::endl;
            return 0;
        }
        if (cmd == "ADD") {
            book.addContact();
        } else if (cmd == "SEARCH") {
            book.searchContacts();
        } else if (cmd == "EXIT") {
            break;
        } else {
            std::cout << "Invalid command (use ADD/SEARCH/EXIT)\n";
        }
    }
    return 0;
}
