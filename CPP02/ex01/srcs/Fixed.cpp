#include "Fixed.hpp"



Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _value(value)
{
	std::cout << "Int constructor called with" << value << std::endl;
	_value <<= _stash;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called with " << value  << std::endl;
	_value = roundf(value * (1 << _stash));
}


Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_value = other.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignement operator called" << std::endl;

	if (this != &other)
		this->_value = other.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Default destructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
	return ((float)_value / (float)(1 << _stash));
}

int Fixed::toInt(void) const
{
	return (_value >> _stash);
}


int Fixed::getRawBits(void) const
{
	return (_value);
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixPoint)
{
	out << fixPoint.toFloat();
	return (out);
}

