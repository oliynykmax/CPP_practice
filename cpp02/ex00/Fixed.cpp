#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const Fixed &src) {
    std::cout << "Copy constructor called" << std::endl;
    this->_value = src.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &src) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src) {
		this->_value = src.getRawBits();
	}
	return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

// Default constructor called
// Copy constructor called
// getRawBits member function called
// Default constructor called
// Copy assignment operator called
// getRawBits member function called
// getRawBits member function called
// 0
// getRawBits member function called
// 0
// getRawBits member function called
// 0
// Destructor called
// Destructor called
// Destructor called
