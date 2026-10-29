
#include "def.hpp"
#include "func.hpp"

int main( void )
{
	{
		char a = 'c';
		char b = 'C';
		std::cout << GRAY << "//Char\n" << RESET;
		std::cout << BLUE << "swap" << RESET << " a: " << a << ", b: " << b << '\n'; 
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << "\n";
		std::cout << YELLOW << "min( a, b ) = " << RESET << ::min( a, b ) << "\n";
		std::cout << ORANGE << "max( a, b ) = " << RESET << ::max( a, b ) << "\n";
	}
	std::cout << "\n";
	{
		int a = 2;
		int b = 3;
		std::cout << GRAY << "//Int\n" << RESET;
		std::cout << BLUE << "swap" << RESET << " a: " << a << ", b: " << b << '\n'; 
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << "\n";
		std::cout << YELLOW << "min( a, b ) = " << RESET << ::min( a, b ) << "\n";
		std::cout << ORANGE << "max( a, b ) = " << RESET << ::max( a, b ) << "\n";
	}
	std::cout << "\n";
	{
		std::string a = "chaine1";
		std::string b = "chaine2";

		std::cout << GRAY << "//String\n" << RESET;
		std::cout << BLUE << "swap " << RESET << "a: " << a << ", b: " << b << '\n'; 
		::swap(a, b);
		std::cout << "a = " << a << ", b = " << b << "\n";
		std::cout << YELLOW << "min( a, b ) = " << RESET << ::min( a, b ) << "\n";
		std::cout << ORANGE << "max( a, b ) = " << RESET << ::max( a, b ) << "\n";
	}
	return 0;
}
