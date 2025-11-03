#include "Fixed.hpp"

Fixed::Fixed () {
	this->value = 0;
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed (const Fixed &fixed) {
	// std::cout << "Copy constuctor called" << std::endl;
	Fixed::operator=(fixed);
}

Fixed::Fixed (const int intValue) {
	// std::cout << "Int constructor called" << std::endl;
	this->value = intValue << this->fbits;
}

Fixed::Fixed (const float floatValue) {
	// std::cout << "Float constructor called" << std::endl;
	this->value = roundf(floatValue * (1 << this->fbits));
}

int	Fixed::toInt() const {
	return this->value >> this->fbits;
}

float	Fixed::toFloat() const {
	return (float)this->value / (1 << this->fbits);
}

Fixed &Fixed::operator=(const Fixed &other) {
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->setRawBits(other.getRawBits());
	return *this;
}

Fixed::~Fixed (){
	// std::cout << "Destructor called" << std::endl;
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

bool Fixed::operator==(const Fixed &other) {
	if (this->value == other.value)
		return true;
	return false;
}

bool Fixed::operator!=(const Fixed &other) {
	if (this->value != other.value)
		return true;
	return false;
}

bool Fixed::operator<(const Fixed &other) {
	if (this->value < other.value)
		return true;
	return false;
}

bool Fixed::operator<=(const Fixed &other) {
	if (this->value <= other.value)
		return true;
	return false;
}

bool Fixed::operator>(const Fixed &other) {
	if (this->value > other.value)
		return true;
	return false;
}

bool Fixed::operator>=(const Fixed &other) {
	if (this->value >= other.value)
		return true;
	return false;
}

Fixed Fixed::operator+(const Fixed &other) const {
	Fixed result;
	result.setRawBits(this->getRawBits() + other.getRawBits());
	return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
	Fixed result;
	result.setRawBits(this->getRawBits() - other.getRawBits());
	return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
	Fixed result;
	long long mul = (long long)this->getRawBits() * (long long)other.getRawBits();
	result.setRawBits((int)(mul >> this->fbits));
	return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
	Fixed result;
	if (other.getRawBits() == 0) {
		std::cerr << "Error: Division by zero" << std::endl;
		result.setRawBits(0);
		return result;
	}
	long long div = ((long long)this->getRawBits() << this->fbits) / (long long)other.getRawBits();
	result.setRawBits((int)div);
	return result;
}

Fixed &Fixed::operator++() {
	this->value++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed	temp = *this;
	this->value++;
	return temp;
}

Fixed &Fixed::operator--() {
	this->value--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed	temp = *this;
	this->value--;
	return temp;
}

Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	if (a.value >= b.value)
		return (Fixed&)a;
	return (Fixed&)b;
}

Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	if (a.value <= b.value)
		return (Fixed&)a;
	return (Fixed&)b;
}
