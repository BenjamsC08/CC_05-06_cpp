#include "Curse.hpp"

Curse::Curse() : AMateria("curse")
{
	if (DISP_DEBUG > 1)
	{
		std::cout << GREEN << "Construct Curse";
		std::cout << RESET << std::endl;
	}
}

Curse::Curse(const Curse &other) : AMateria(other)
{
	this->_type = other._type;
}

Curse &Curse::operator=(const Curse &other)
{
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

Curse::~Curse()
{
	if (DISP_DEBUG > 1)
	{
		std::cout << GREEN << "Destruct Curse";
		std::cout << RESET << std::endl;
	}
}

AMateria* Curse::clone() const
{
	return (new Curse());
}
