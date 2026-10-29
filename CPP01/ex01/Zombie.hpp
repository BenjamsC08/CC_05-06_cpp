#ifndef __ZOMBIE__
#define __ZOMBIE__

#include <string>
#include <ostream>
#include <iostream>

class Zombie
{
	public:
		Zombie();
		Zombie(std::string);
		Zombie(const Zombie &);
		Zombie &operator=(const Zombie &);
		~Zombie();

		void announce(void);
		void setNameZombie(std::string name);
		const std::string &getNameZombie(std::string name) const;

	private:
		std::string name;
		
};

Zombie *newZombie(std::string name);
void randomChump (std::string name);
Zombie	*zombieHorde(int N, std::string name);

#endif
