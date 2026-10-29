
#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
}
HumanB::HumanB(const HumanB &other) : name(other.name)
{}

HumanB &HumanB::operator=(const HumanB &other)
{
	if (this != &other)
		this->name = other.name;
	return (*this);
}

HumanB::~HumanB()
{
}

void HumanB::attack() const
{
	std::cout << this->name << " attack with " << this->tool->getType() << std::endl;
}


void HumanB::setWeapon(Weapon &tool)
{
	this->tool = &tool;
}

