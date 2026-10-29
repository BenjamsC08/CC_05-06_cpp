#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "Constructor WrongCat" << std::endl;
	this->setType("WrongCat");
}

WrongCat::WrongCat(const WrongCat &other)
{
	this->setType(other.getType());
}

WrongCat	  &WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
		this->_type = other.getType();
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "Destructor WrongCat" << std::endl;
}
