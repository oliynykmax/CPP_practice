#include "Cat.hpp"
#include <iostream>
#include <format>

Cat::Cat() : Animal(){
    type = "Cat";
    std::cout << std::format("Cat constructor called for {}\n", type);
}

Cat::~Cat() {
    std::cout << std::format("Cat destructor called for {}\n", type);
}

void Cat::makeSound() const {
    std::cout << std::format("Cat makes meow meow meow\n");
}
