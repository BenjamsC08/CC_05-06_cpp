#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->setHitPoint(100);
	this->setEnergyPoint(50);
	this->setAttackDamage(20);
	std::cout << "construct ScavTrap `" << this->getName() << "`" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	this->setName(other.getName());
	this->setHitPoint(other.getHitPoint());
	this->setEnergyPoint(other.getEnergyPoint());
	this->setAttackDamage(other.getAttackDamage());
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		this->ClapTrap::operator=(other);
		this->setName(other.getName());
		this->setHitPoint(other.getHitPoint());
		this->setEnergyPoint(other.getEnergyPoint());
		this->setAttackDamage(other.getAttackDamage());
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "destruct ScavTrap `" << this->getName() << "`" << std::endl;
}


void ScavTrap::attack(const std::string &target)
{
	if (!this->getHitPoint())
		this->noHealth();
	else if (!this->getEnergyPoint())
		this->noEnergy();
	else
	{
		this->setEnergyPoint(this->getEnergyPoint() - 1);
		std::cout << GREEN << "ScavTrap `" << this->getName() << "` attack " << target << ", causing ";
		std::cout << this->getAttackDamage() << " points of damage !";
		std::cout << YELLOW << " (energy point left: " << this->getEnergyPoint() << ")" << RESET << std::endl;
	}
}

void ScavTrap::guardGate()
{
	std::cout << TEAL << this->getName() << " is now in gate keeper mode " << RESET << std::endl;
}
