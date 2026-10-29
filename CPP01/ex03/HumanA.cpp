#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &tool) : tool(tool)
{
	this->name = name;
}
HumanA::HumanA(const HumanA &other) : name(other.name), tool(other.tool)
{}

HumanA &HumanA::operator=(const HumanA &other)
{
	this->name = other.name;
	this->tool = other.tool;
	return (*this);
}

HumanA::~HumanA(){}

void HumanA::attack() const
{
	std::cout << this->name << " attack with " << this->tool.getType() << std::endl;
}
