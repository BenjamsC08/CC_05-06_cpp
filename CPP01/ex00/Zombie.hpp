#ifndef __ZOMBIE__
#define __ZOMBIE__

#include <string>
#include <ostream>
#include <iostream>

class Zombie
{
	public:
		Zombie(std::string);
		Zombie(const Zombie &other);
		Zombie &operator=(const Zombie &other);
		~Zombie();

		void announce(void);
		void setNameZombie(std::string name);
		const std::string &getNameZombie(std::string name) const;

	private:
		std::string name;
		
};

Zombie *newZombie(std::string name);
void randomChump (std::string name);

#endif
