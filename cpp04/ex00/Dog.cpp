#include "Dog.hpp"
#include <iostream>
#include <format>

Dog::Dog() : Animal(){
    type = "Dog";
    std::cout << std::format("Dog constructor called for {}\n", type);
}

Dog::~Dog() {
    std::cout << std::format("Dog destructor called for {}\n", type);
}

void Dog::makeSound() const {
    std::cout << std::format("Dog makes rar wuf and bark\n");
}
