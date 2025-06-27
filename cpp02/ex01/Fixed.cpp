#include "Fixed.hpp"
#include <iostream>
#include <cmath>

static const int _fractional_bits = 8;

Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const Fixed &src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::Fixed(const int num) : _value(num << _fractional_bits) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num) : _value(roundf(num * (1 << _fractional_bits))) {
    std::cout << "Float constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &src) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src) {
		this->_value = src.getRawBits();
	}
	return *this;
}

std::ostream &operator<<(std::ostream& os, const Fixed& fixed){
	os << fixed.toFloat();
	return os;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    return this->_value;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(this->_value) / (1 << _fractional_bits);
}

int Fixed::toInt(void) const {
    return this->_value >> _fractional_bits;
}
