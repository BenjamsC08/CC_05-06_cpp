#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed c(42.42f);
	
	
	std::cout << "a :" << a;
	std::cout <<", b :" << b;
	std::cout << ", c :" << c << std::endl << std::endl;

	std::cout << "a pre increment:" << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl << std::endl;

	std::cout << "a post increment:" << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl << std::endl;

	std::cout << "a pre decrement:" << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl << std::endl;

	std::cout << "c post decrement:" << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl << std::endl;

	a = 2;
	std::cout << "a = 2 :" << a << std::endl;

	c = a + b;
	std::cout << "a + b = " << c << std::endl;
	
	std::cout << "a.toInt()" << a.toInt() << std::endl;


	std::cout << "max( a, b ) a: " << a << " b: " << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << "min( a, c ) a: " << a << " c: " << c << std::endl;
	std::cout << Fixed::min( a, c ) << std::endl;
	return 0;
}
