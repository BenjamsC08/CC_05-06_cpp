#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap A("ClopeTroop");

	A.attack("Smoker");
	A.takeDamage(8);
	A.beRepaired(1);
	A.beRepaired(1);
	A.beRepaired(1);
	A.beRepaired(1);
	A.beRepaired(1);
	A.beRepaired(1);
	A.beRepaired(1);
	A.beRepaired(1);
	A.beRepaired(1);
	
	A.beRepaired(1);
	A.attack("Smoker");

	A.takeDamage(12);

	A.beRepaired(1);
	A.attack("Smoker");
	A.takeDamage(100);
}
