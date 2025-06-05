#include <iostream>
#include "Harl.hpp"
#include <string>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: ./harlFilter <level>\n (DEBUG, INFO, WARNING, ERROR)" << std::endl;
        return 1;
    }
    Harl harl;
    std::string level = argv[1];

    int index = -1;
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++) {
        if (level == levels[i]) {
            index = i;
            break;
        }
    }

    switch (index) {
        case 0:
        	std::cout << "[DEBUG]" << std::endl;
            harl.complain("DEBUG");
            [[fallthrough]];
        case 1:
        	std::cout << "[INFO]" << std::endl;
            harl.complain("INFO");
            std::cout << std::endl;
            [[fallthrough]];
        case 2:
        	std::cout << "[WARNING]" << std::endl;
            harl.complain("WARNING");
            std::cout << std::endl;
            [[fallthrough]];
        case 3:

        	std::cout << "[ERROR]" << std::endl;
            harl.complain("ERROR");
            std::cout << std::endl;
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
    return 0;
}
