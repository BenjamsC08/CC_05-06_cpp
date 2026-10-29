# include "MateriaSource.hpp"


MateriaSource::MateriaSource() : _stock(0)
{
	if (DISP_DEBUG > 1)
		std::cout << CYAN << "Construct Materia Source" << RESET << std::endl;
	this->_spells = new AMateria*[MAX_ITEMS];
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	this->_stock = other._stock;
	for (int i=0; i < MAX_ITEMS; i++)
		this->_spells[i] = other._spells[i]->clone();
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		AMateria **tmp;
		tmp = new AMateria*[MAX_ITEMS];
		for (int i=0; i < MAX_ITEMS; i++)
		{
			if (other._spells[i])
				tmp[i] = other._spells[i]->clone();
		}
		this->_stock = other._stock;
		for (int i=0; i < MAX_ITEMS; i++)
		{
			if (this->_spells[i])
				delete this->_spells[i];
		}
		delete[] this->_spells;
		this->_spells = tmp;
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	if (DISP_DEBUG > 1)
		std::cout << CYAN << "Destruct Materia Source" << RESET << std::endl;
	for (int i = 0; i < this->_stock; i++)
	{
		if (this->_spells[i])
			delete this->_spells[i];
	}
	delete [] this->_spells;
}

void MateriaSource::learnMateria(AMateria *spell)
{
	if (!spell)
		return ;
	if (this->_stock < 4)
	{
		this->_spells[this->_stock] = spell;
		this->_stock++;
	}
	else
	{
		if (DISP_DEBUG > 0)
			std::cout << ORANGE << "Source cannot take more spell" << RESET << std::endl;
		delete spell;
	}
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < this->_stock; i++)
	{
		if (this->_spells[i]->getType() == type)
			return (this->_spells[i]->clone());
	}
	if (DISP_DEBUG > 0)
		std::cout << MAGENTA << "Spell not in your source" << RESET << std::endl;
	return (NULL);
}
