#include "Dog.hpp"

Dog::Dog()
{
	std::cout << GREEN << "Constructor Dog" << RESET << std::endl;
	this->setType("Dog");
	this->_brain = new Brain();
}

Dog::Dog(const Dog &other)
{
	this->setType(other.getType());
	this->_brain = new Brain(*other._brain);
}

Dog	  &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
		this->_type = other.getType();
	}
	return (*this);
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << RED << "Destructor Dog" << RESET << std::endl;
}

