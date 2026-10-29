#include "Character.hpp"

Character::Character(std::string name) : _name(name), _equip(0), _trash_size(0)
{
	if (DISP_DEBUG > 1)
	{
		std::cout << PURPLE << "Construct of `" << name;
		std::cout << "' the new Character" << RESET << std::endl;
	}
	this->_inventory = new AMateria*[MAX_ITEMS];
	for (int i=0; i < MAX_ITEMS; i++)
		this->_inventory[i] = NULL;
	this->_trash = new AMateria*[0];
}

Character::Character(const Character &other) : _name(other._name), _equip(other._equip),  _trash_size(other._trash_size)
{
	this->_inventory = new AMateria*[MAX_ITEMS];
	for (int i=0; i < MAX_ITEMS; i++)
	{
		if (other._inventory[i])
			this->_inventory[i] = other._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	this->_trash = new AMateria*[_trash_size];
	for (int i=0; i < other._trash_size; i++)
		this->_trash[i] = other._trash[i]->clone();
}

Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_equip = other._equip;
		this->_trash_size = other._trash_size;

		for (int i=0; i < MAX_ITEMS; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
			if (other._inventory[i])
				this->_inventory[i] = other._inventory[i]->clone();
			else
	   			this->_inventory[i] = NULL;
		}
		for (int i = 0; i < _trash_size; i++)
			delete _trash[i];
		delete[] _trash;
		_trash = new AMateria*[_trash_size];
		for (int i = 0; i < _trash_size; i++)
			_trash[i] = other._trash[i]->clone();
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < MAX_ITEMS; i++)
	{
		if (this->_inventory[i])
			delete _inventory[i];
	}
	delete[] this->_inventory;
	for (int i = 0; i < _trash_size; i++)
		delete _trash[i];
	delete[] _trash;
	if (DISP_DEBUG > 1)
	{
		std::cout << PURPLE << "Destruct of `" << this->_name;
		std::cout << "' the Character" << RESET << std::endl;
	}
}

std::string const &Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	if (!m)
	{
		std::cout << "Materia null" << std::endl;
		return ;
	}
	else if (this->_equip >= MAX_ITEMS)
	{
		if (DISP_DEBUG > 0)
		{
			std::cout << ORANGE << "Inventory of " << this->getName();
			std::cout << " cannot take more spell" << RESET << std::endl;
		}
		delete m;
	}
	else
	{
		for (int i=0; i < MAX_ITEMS; i++)
		{
			if (!this->_inventory[i])
			{
				this->_inventory[i] = m;
				this->_equip++;
				return ;
			}
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= MAX_ITEMS || !this->_inventory[idx])
	{
		if (DISP_DEBUG > 0)
			std::cout << ORANGE << "cannot access to this idx : " << idx << RESET << std::endl;
		return ;
	}
	AMateria **newTrash = new AMateria*[this->_trash_size + 1];
	for (int i=0; i < this->_trash_size; i++)
		newTrash[i] = this->_trash[i];
	newTrash[this->_trash_size] = this->_inventory[idx];
	delete[] this->_trash;
	this->_trash = newTrash;
	this->_trash_size++;
	this->_inventory[idx] = NULL;
	this->_equip--;
}

void Character::use(int idx, ICharacter& target)
{ 
	if (idx < 0 || idx > MAX_ITEMS || !this->_inventory[idx])
	{
		if (DISP_DEBUG > 0)
			std::cout << ORANGE << "cannot use this idx : " << idx << RESET << std::endl;
		return;
	}	
	this->_inventory[idx]->use(target);
}

void Character::use(std::string const type, ICharacter& target)
{ 
	for (int i=0; i < MAX_ITEMS && this->_inventory[i]; i++)
	{
		if (this->_inventory[i]->getType() == type)
		{
			this->_inventory[i]->use(target);
			return ;
		}
	}
	if (DISP_DEBUG > 0)
		std::cout << ORANGE << "No spell named `" << type << "'" << RESET << std::endl;
}
