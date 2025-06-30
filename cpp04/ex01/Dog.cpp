#include "Dog.hpp"
#include <iostream>


Dog::Dog() : Animal() {
    type = "Dog";
    _brain = new Brain();
    std::cout << "Dog constructor called for " << type << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    _brain = new Brain(*other._brain);
    std::cout << "Dog copy constructor called for " << type << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
        delete _brain;
        _brain = new Brain(*other._brain);
    }
    std::cout << "Dog assignment operator called for " << type << std::endl;
    return *this;
}

Dog::~Dog() {
    delete _brain;
    std::cout << "Dog destructor called for " << type << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Dog makes rar wuf and bark" << std::endl;
}

Brain* Dog::getBrain() const {
    return _brain;
}
