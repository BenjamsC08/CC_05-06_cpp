#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap B("GAV");

	for (int i=0; i < 24; i++)
		B.attack("Clope");
	for (int i=0; i < 24; i++)
		B.takeDamage(1);
	B.guardGate();
	for (int i=0; i < 29; i++)
		B.beRepaired(20);

	B.takeDamage(6000);
	B.beRepaired(20);
}
