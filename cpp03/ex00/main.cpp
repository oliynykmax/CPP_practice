#include "ClapTrap.hpp"
#include <iostream>
#include <stdexcept>

int main(int ac, char **argv) {
    std::string name = ac == 2 ? argv[1] : "Trump";

    try {
        ClapTrap a(NULL);
    }
    catch (const std::logic_error &e){
        std::cout << "can't create with the null name\n";
    }
    ClapTrap a(name);
    ClapTrap b(a);
    ClapTrap c("rino");
    b = c;
    a.takeDamage(1);
    a.beRepaired(2);
    for (int i = 0; i < 5; i++)
        a.attack("democracy");
    for (int i = 0; i < 5; i++)
        a.takeDamage(i);
    for (int i = 0; i < 5; i++)
        a.beRepaired(i);

}
