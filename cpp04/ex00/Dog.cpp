#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal() {
    type = "Dog";
    std::cout << "Dog constructor called for " << type << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog destructor called for " << type << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    type = other.type;
    std::cout << "Dog copy constructor called for " << type << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    Animal::operator=(other);
    std::cout << "Dog assignment operator called for " << type << std::endl;
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Dog makes rar wuf and bark" << std::endl;
}
