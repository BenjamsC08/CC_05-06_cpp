#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->setHitPoint(100);
	this->setEnergyPoint(100);
	this->setAttackDamage(30);
	std::cout << "construct FragTrap `" << this->getName() << "`" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	this->setName(other.getName());
	this->setHitPoint(other.getHitPoint());
	this->setEnergyPoint(other.getEnergyPoint());
	this->setAttackDamage(other.getAttackDamage());
}

FragTrap &FragTrap::operator=(const FragTrap &other)
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

FragTrap::~FragTrap()
{
	std::cout << "destruct FragTrap `" << this->getName() << "`" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (!this->getHitPoint())
		this->noHealth();
	else if (!this->getEnergyPoint())
		this->noEnergy();
	else
	{
		this->setEnergyPoint(this->getEnergyPoint() - 1);
		std::cout << GREEN << "FragTrap `" << this->getName() << "` attack " << target << ", causing ";
		std::cout << this->getAttackDamage() << " points of damage !";
		std::cout << YELLOW << " (energy point left: " << this->getEnergyPoint() << ")" << RESET << std::endl;
	}
}

void FragTrap::highFivesGuys(void)
{
	std::cout << TEAL << "Let's do a high five guys" << RESET << std::endl;
}
