#include "FragTrap.hpp"

int main(void)
{
	FragTrap B("Gotaga");

	for (int i=0; i < 75; i++)
		B.attack("Vitality");
	for (int i=0; i < 30; i++)
		B.takeDamage(2);
	for (int i=0; i < 26; i++)
		B.beRepaired(2);

	B.takeDamage(6000);
	B.beRepaired(20);
	B.highFivesGuys();
}
