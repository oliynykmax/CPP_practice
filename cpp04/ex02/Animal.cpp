#include "Animal.hpp"
#include <iostream>
#include <format>

Animal::Animal() : type("Base") {
    std::cout << std::format("Base constructor called\n");
}

Animal::~Animal() {
    std::cout << std::format("{} destructor called\n", type);
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
