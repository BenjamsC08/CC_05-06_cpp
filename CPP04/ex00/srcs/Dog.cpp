#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Constructor Dog" << std::endl;
	this->setType("Dog");
}

Dog::Dog(const Dog &other)
{
	this->setType(other.getType());
}

Dog	  &Dog::operator=(const Dog &other)
{
	if (this != &other)
		this->_type = other.getType();
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Destructor Dog" << std::endl;
}

