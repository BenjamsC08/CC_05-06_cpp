# include "AMateria.hpp"
# include "ICharacter.hpp"

AMateria::AMateria(std::string const &type)
{
	if (DISP_DEBUG > 1)
	{
		std::cout << YELLOW << "Construct AMateria (with type: " << type << ")";
		std::cout << std::endl;
	}
	this->_type = type;
}

AMateria::AMateria(const AMateria &other) : _type(other._type)
{}

AMateria &AMateria::operator=(const AMateria &other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

AMateria::~AMateria()
{
	if (DISP_DEBUG > 1)
		std::cout << RED << "Destruct AMateria" << RESET << std::endl;
}

std::string const &AMateria::getType() const
{
	return (this->_type);
}

void AMateria::setType(std::string type)
{
	this->_type = type;
}

void AMateria::use(ICharacter& target)
{
	if (this->getType() == "ice")
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	if (this->getType() == "cure")
		std::cout << "* heals " << target.getName() << "'s wound *" << std::endl;
	if (this->getType() == "fireball")
		std::cout << "* throw fireball to " << target.getName() << " *" << std::endl;
	if (this->getType() == "curse")
		std::cout << "* " << target.getName() << " will wither away wound *" << std::endl;
}
