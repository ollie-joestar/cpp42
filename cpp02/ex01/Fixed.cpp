#include "Fixed.hpp"

Fixed::Fixed () {
	this->value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed (const Fixed &fixed) {
	std::cout << "Copy constuctor called" << std::endl;
	Fixed::operator=(fixed);
}

Fixed::Fixed (const int intValue) {
	std::cout << "Int constructor called" << std::endl;
	this->value = intValue << this->fbits;
}

Fixed::Fixed (const float floatValue) {
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(floatValue * (1 << this->fbits));
}

int	Fixed::toInt() const {
	return this->value >> this->fbits;
}

float	Fixed::toFloat() const {
	return (float)this->value / (1 << this->fbits);
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->setRawBits(other.getRawBits());
	return *this;
}

Fixed::~Fixed (){
	std::cout << "Destructor called" << std::endl;
};

int	Fixed::getRawBits() const {
	// std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}

void	Fixed::setRawBits ( int const raw ) {
	this->value = raw;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}
