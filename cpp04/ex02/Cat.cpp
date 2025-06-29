#include "Cat.hpp"
#include <iostream>
#include <format>

Cat::Cat() : Animal() {
    type = "Cat";
    _brain = new Brain();
    std::cout << std::format("Cat constructor called for {}\n", type);
}

Cat::Cat(const Cat& other) : Animal(other) {
    _brain = new Brain(*other._brain);
    std::cout << std::format("Cat copy constructor called for {}\n", type);
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);
        delete _brain;
        _brain = new Brain(*other._brain);
    }
    std::cout << std::format("Cat assignment operator called for {}\n", type);
    return *this;
}

Cat::~Cat() {
    delete _brain;
    std::cout << std::format("Cat destructor called for {}\n", type);
}

void Cat::makeSound() const {
    std::cout << std::format("Cat makes meow meow meow\n");
}

Brain* Cat::getBrain() const {
    return _brain;
}
