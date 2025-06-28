#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <compare>

class Fixed {
	private:
		int _value;
		static const int _fractional_bits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &other);
		Fixed(const int num);
		Fixed(const float num);
		Fixed &operator=(const Fixed &src);
		friend std::ostream &operator<<(std::ostream& os, const Fixed& fixed);
		int	getRawBits( void ) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

		std::strong_ordering operator<=>(const Fixed& other) const;
		bool operator==(const Fixed& other) const;

		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;

		Fixed& operator+=(const Fixed& other);
		Fixed& operator-=(const Fixed& other);
		Fixed& operator*=(const Fixed& other);
		Fixed& operator/=(const Fixed& other);

		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);

		static Fixed max(Fixed& a, Fixed& b);
		static Fixed min(Fixed& a, Fixed& b);
		static Fixed max(const Fixed& a, const Fixed& b);
		static Fixed min(const Fixed& a, const Fixed& b);
};

#endif
