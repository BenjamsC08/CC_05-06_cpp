#include "Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::Weapon(std::string name)
{
	this->type = name;
}

Weapon::Weapon(const Weapon &other) : type(other.type)
{}

Weapon &Weapon::operator=(const Weapon &other) 
{
	if (this != &other)
		this->type = other.type;
	return (*this);
}

Weapon::~Weapon(){}

const std::string &Weapon::getType() const
{
	return(this->type);
}

void Weapon::setType(std::string type)
{
	this->type = type;
}
