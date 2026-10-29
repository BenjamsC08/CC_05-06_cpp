#include "Zombie.hpp"

int main()
{
	Zombie z1("z1");
	randomChump("zR");
	z1.announce();
	Zombie *z2 = newZombie("z2");
	z2->announce();
	delete z2;
}
