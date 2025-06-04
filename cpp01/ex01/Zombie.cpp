#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::~Zombie() {std::cout << name << " was eliminated for good" << std::endl;}

void Zombie::setName(std::string name) {
    this->name = name;
}

void Zombie::announce() {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
