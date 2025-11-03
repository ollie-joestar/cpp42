#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const c( Fixed( 5.05f ) + Fixed( 2 ) );
	Fixed const d( Fixed( 5.05f ) - Fixed( 2 ) );
	Fixed const e( Fixed( 5.05f ) / Fixed( 2 ) );
	
	std::cout << "Value of a: 				" << a << std::endl;
	std::cout << "Value of a pre-increment:		" << ++a << std::endl;
	std::cout << "Value of a pre-increment:		" << ++a << std::endl;
	std::cout << "Value of a after pre-increment:		" << a << std::endl;
	std::cout << "Value of a post-increment:		" << a++ << std::endl;
	std::cout << "Value of a after post-increment:	" << a << std::endl;

	std::cout << "================================" << std::endl;

	std::cout << "5.05f * 2 = b =				" << b << std::endl;
	std::cout << "5.05f + 2 = c =				" << c << std::endl;
	std::cout << "5.05f - 2 = d =				" << d << std::endl;
	std::cout << "5.05f / 2 = e =				" << e << std::endl;

	std::cout << "================================" << std::endl;

	std::cout << "Max between " << a << " and " <<  b << ":	" << Fixed::max( a, b ) << std::endl;
	std::cout << "Min between " << a << " and " <<  b << ":	" << Fixed::min( a, b ) << std::endl;

	return 0;
}
