#include "Fixed.hpp"
#include <iostream>
#include <cmath>

static const int _fractional_bits = 8;

Fixed::Fixed() : _value(0) { }
Fixed::~Fixed() { }

Fixed::Fixed(const Fixed &src) { *this = src; }

Fixed::Fixed(const int num) : _value(num << _fractional_bits) { }

Fixed::Fixed(const float num) : _value(roundf(num * (1 << _fractional_bits))) { }

Fixed &Fixed::operator=(const Fixed &src) {
	if (this != &src) {
		this->_value = src.getRawBits();
	}
	return *this;
}

std::strong_ordering Fixed::operator<=>(const Fixed& other) const {
    return _value <=> other._value;
}

bool Fixed::operator==(const Fixed& other) const { return _value == other._value; }

Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result._value = this->_value + other._value;
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result._value = this->_value - other._value;
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;
    long long temp = (long long)this->_value * other._value;
    result._value = temp >> _fractional_bits;
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
    Fixed result;
    long long temp = ((long long)this->_value << _fractional_bits) / other._value;
    result._value = temp;
    return result;
}

Fixed& Fixed::operator+=(const Fixed& other) {
    this->_value += other._value;
    return *this;
}

Fixed& Fixed::operator-=(const Fixed& other) {
    this->_value -= other._value;
    return *this;
}

Fixed& Fixed::operator*=(const Fixed& other) {
    long long temp = (long long)this->_value * other._value;
    this->_value = temp >> _fractional_bits;
    return *this;
}

Fixed& Fixed::operator/=(const Fixed& other) {
    long long temp = ((long long)this->_value << _fractional_bits) / other._value;
    this->_value = temp;
    return *this;
}

Fixed& Fixed::operator++() {
    this->_value += (1 << _fractional_bits);
    return *this;
}

Fixed& Fixed::operator--() {
    this->_value -= (1 << _fractional_bits);
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++(*this);
    return temp;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --(*this);
    return temp;
}

std::ostream &operator<<(std::ostream& os, const Fixed& fixed){
	os << fixed.toFloat();
	return os;
}

int Fixed::getRawBits(void) const { return this->_value; }

void Fixed::setRawBits(int const raw) { this->_value = raw; }

float Fixed::toFloat(void) const { return static_cast<float>(this->_value) / (1 << _fractional_bits); }

int Fixed::toInt(void) const { return this->_value >> _fractional_bits; }

Fixed Fixed::max(const Fixed& a, const Fixed& b) { return (a > b) ? a : b; }

Fixed Fixed::min(const Fixed& a, const Fixed& b) { return (a < b) ? a : b; }
