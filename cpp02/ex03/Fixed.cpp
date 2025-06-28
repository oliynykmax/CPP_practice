#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _value(0) { }
Fixed::~Fixed() { }

Fixed::Fixed(const Fixed &src) { *this = src; }

Fixed::Fixed(const int num) : _value(num << _fractional_bits) { }

Fixed::Fixed(const float num) : _value(roundf(num * (1 << _fractional_bits))) { }

Fixed &Fixed::operator=(const Fixed &src) {
	if (this != &src) {
		setRawBits(src.getRawBits());
	}
	return *this;
}

std::strong_ordering Fixed::operator<=>(const Fixed& other) const {
    return _value <=> other._value;
}

bool Fixed::operator==(const Fixed& other) const { return _value == other._value; }

Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result.setRawBits(_value + other._value);
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result.setRawBits(_value - other._value);
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;
    long long temp = (long long)_value * other._value;
    result.setRawBits(temp >> _fractional_bits);
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
    Fixed result;
    long long temp = ((long long)_value << _fractional_bits) / other._value;
    result.setRawBits(temp);
    return result;
}

Fixed& Fixed::operator+=(const Fixed& other) {
    setRawBits(_value + other._value);
    return *this;
}

Fixed& Fixed::operator-=(const Fixed& other) {
    setRawBits(_value - other._value);
    return *this;
}

Fixed& Fixed::operator*=(const Fixed& other) {
    long long temp = (long long)_value * other._value;
    setRawBits(temp >> _fractional_bits);
    return *this;
}

Fixed& Fixed::operator/=(const Fixed& other) {
    long long temp = ((long long)_value << _fractional_bits) / other._value;
    setRawBits(temp);
    return *this;
}

Fixed& Fixed::operator++() {
    setRawBits(_value + (1 << _fractional_bits));
    return *this;
}

Fixed& Fixed::operator--() {
    setRawBits(_value - (1 << _fractional_bits));
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

int Fixed::getRawBits(void) const { return _value; }

void Fixed::setRawBits(int const raw) { _value = raw; }

float Fixed::toFloat(void) const { return static_cast<float>(_value) / (1 << _fractional_bits); }

int Fixed::toInt(void) const { return _value >> _fractional_bits; }

Fixed Fixed::max(const Fixed& a, const Fixed& b) { return (a > b) ? a : b; }

Fixed Fixed::min(const Fixed& a, const Fixed& b) { return (a < b) ? a : b; }

Fixed Fixed::max(Fixed& a, Fixed& b) { return (a > b) ? a : b; }

Fixed Fixed::min(Fixed& a, Fixed& b) { return (a < b) ? a : b; }
