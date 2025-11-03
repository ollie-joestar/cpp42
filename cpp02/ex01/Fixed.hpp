#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed {
	private:
		int	value;
		static const int fbits = 8;
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		Fixed(const int intValue);
		Fixed(const float floatValue);
		Fixed& operator=(const Fixed &other);
		~Fixed();

		float toFloat(void) const;
		int toInt(void) const;
		int	getRawBits(void) const;
		void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif // FIXED_HPP
