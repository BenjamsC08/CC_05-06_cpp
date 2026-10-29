#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _value(value)
{
	// std::cout << "Int constructor called with" << value << std::endl;
	_value <<= _stash;
}

Fixed::Fixed(const float value)
{
	// std::cout << "Float constructor called with " << value  << std::endl;
	_value = roundf(value * (1 << _stash));
}


Fixed::Fixed(const Fixed &other)
{
	// std::cout << "Copy constructor called" << std::endl;
	this->_value = other.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &other)
{
	// std::cout << "Copy assignement operator called" << std::endl;
	if (this != &other)
		this->_value = other._value;
	return (*this);
}

Fixed::~Fixed()
{
	// std::cout << "Default destructor called" << std::endl;
}

/*
*
*					ACCESSORS
*
*/

int Fixed::getRawBits(void) const
{
	return (_value);
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)_value / (1 << _stash));
}

int Fixed::toInt(void) const
{
	return (_value >> _stash);
}

/*
*
*					STREAM
*
*/

std::ostream& operator<<(std::ostream &out, const Fixed &fixPoint)
{
	out << fixPoint.toFloat();
	return (out);
}

/*
*
*					LOGIC
*
*/

bool Fixed::operator>(const Fixed &other)
{
	int n = this->getRawBits() - other.getRawBits();

	if (n > 0)
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed &other)
{
	int n = this->getRawBits() - other.getRawBits();

	if (n > 0)
		return (false);
	return (true);
}

bool Fixed::operator>=(const Fixed &other)
{
	int n = this->getRawBits() - other.getRawBits();

	if (n >= 0)
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed &other)
{
	int n = this->getRawBits() - other.getRawBits();

	if (n >= 0)
		return (false);
	return (true);
}

bool Fixed::operator==(const Fixed &other)
{
	if (this->getRawBits() == other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed &other)
{
	if (this->getRawBits() == other.getRawBits())
		return (false);
	return (true);
}

/*
*
*					ARITMETIC
*
*/

float Fixed::operator+(const Fixed &other)
{
	return ((float)(this->toFloat() + other.toFloat()));
}

float Fixed::operator-(const Fixed &other)
{
	return ((float)(this->toFloat() - other.toFloat()));
}

float Fixed::operator*(const Fixed &other)
{
	return ((float)(this->toFloat() * other.toFloat()));
}

float Fixed::operator/(const Fixed &other)
{
	if (other.getRawBits() == 0)
		std::cout << "Error : division by 0" << std::endl;
	return ((float)(this->toFloat() / other.toFloat()));
}

/*
*
*					Incr/Decr
*
*/

Fixed Fixed::operator++()
{
	int k = this->getRawBits();
	this->setRawBits(++k);
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed t = *this;
	++*this;
	return (t);
}

Fixed Fixed::operator--()
{
	int k = this->getRawBits();
	this->setRawBits(--k);
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed t = *this;
	--*this;
	return (t);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return(a);
	else
		return(b);
}


Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a < b)
		return(b);
	else
		return(a);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.toInt() < b.toInt())
		return(b);
	else
		return(a);
}

