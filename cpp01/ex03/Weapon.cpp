#include "Weapon.hpp"
#include <string>
#include <iostream>

Weapon::Weapon(std::string type) {
    this->type = type;
}

Weapon::~Weapon() {}

std::string Weapon::getType() const {
    return type;
}

void Weapon::setType(std::string newType) {
    type = newType;
}
