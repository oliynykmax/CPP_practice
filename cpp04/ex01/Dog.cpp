#include "Dog.hpp"
#include <iostream>
#include <format>

Dog::Dog() : Animal() {
    type = "Dog";
    _brain = new Brain();
    std::cout << std::format("Dog constructor called for {}\n", type);
}

Dog::Dog(const Dog& other) : Animal(other) {
    _brain = new Brain(*other._brain);
    std::cout << std::format("Dog copy constructor called for {}\n", type);
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
        delete _brain;
        _brain = new Brain(*other._brain);
    }
    std::cout << std::format("Dog assignment operator called for {}\n", type);
    return *this;
}

Dog::~Dog() {
    delete _brain;
    std::cout << std::format("Dog destructor called for {}\n", type);
}

void Dog::makeSound() const {
    std::cout << std::format("Dog makes rar wuf and bark\n");
}

Brain* Dog::getBrain() const {
    return _brain;
}
