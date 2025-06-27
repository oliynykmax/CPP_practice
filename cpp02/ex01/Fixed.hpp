#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed {
	private:
		int _value;
		static const int _fractional_bits = 8;
	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed(const int num);
		Fixed(const float num);
		Fixed &operator=(const Fixed &src);
		friend std::ostream &operator<<(std::ostream& os, const Fixed& fixed);
		~Fixed();
		int	getRawBits( void ) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

#endif
