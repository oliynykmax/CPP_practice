#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("Base") {
    std::cout << "Base constructor called" << std::endl;
}

Animal::~Animal() {
    std::cout << type << " destructor called" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type) { }

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

std::string Animal::getType() const {
    return type;
}
