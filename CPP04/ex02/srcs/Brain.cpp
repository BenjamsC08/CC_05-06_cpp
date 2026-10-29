# include "Brain.hpp"

Brain::Brain()
{
	std::cout << CYAN << "Constructor Brain" << RESET << std::endl;
}

Brain::Brain(const Brain &other)
{
	for (int i=0; i < 100; i++)
		this->_ideas[i] = other._ideas[i];
}

Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (int i=0; i < 100; i++)
			this->_ideas[i] = other._ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << PURPLE << "Destructor Brain" << RESET << std::endl;

}

