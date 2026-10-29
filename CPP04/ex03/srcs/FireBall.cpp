#include "FireBall.hpp"

FireBall::FireBall() : AMateria("fireball")
{
	if (DISP_DEBUG > 1)
	{
		std::cout << GREEN << "Construct FireBall";
		std::cout << RESET << std::endl;
	}
}

FireBall::FireBall(const FireBall &other) : AMateria(other)
{
	this->_type = other._type;
}

FireBall &FireBall::operator=(const FireBall &other)
{
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

FireBall::~FireBall()
{
	if (DISP_DEBUG > 1)
	{
		std::cout << GREEN << "Destruct FireBall";
		std::cout << RESET << std::endl;
	}
}

AMateria* FireBall::clone() const
{
	return (new FireBall());
}

