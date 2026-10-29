#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap joz("Joz");
	// for (int i=0; i < 75; i++)
	// 	joz.attack("Teach");
	// for (int i=0; i < 30; i++)
	// 	joz.takeDamage(2);
	// for (int i=0; i < 26; i++)
	// 	joz.beRepaired(2);Frag

	std::cout  << " " << joz.getEnergyPoint() << " " << joz.getHitPoint() << "\n";

	joz.takeDamage(6000);
	joz.beRepaired(20);
	joz.whoAmI();
}
