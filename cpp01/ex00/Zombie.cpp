#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(std::string name) {this->name = name;}

Zombie::~Zombie() {std::cout << name << " was eliminated for good" << std::endl;}

void Zombie::announce() {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
