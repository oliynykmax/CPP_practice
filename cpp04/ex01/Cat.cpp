#include "Cat.hpp"
#include <iostream>


Cat::Cat() : Animal() {
    type = "Cat";
    _brain = new Brain();
    std::cout << "Cat constructor called for " << type << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    _brain = new Brain(*other._brain);
    std::cout << "Cat copy constructor called for " << type << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);
        delete _brain;
        _brain = new Brain(*other._brain);
    }
    std::cout << "Cat assignment operator called for " << type << std::endl;
    return *this;
}

Cat::~Cat() {
    delete _brain;
    std::cout << "Cat destructor called for " << type << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Cat makes meow meow meow" << std::endl;
}

Brain* Cat::getBrain() const {
    return _brain;
}
