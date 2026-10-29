#include "Harl.hpp"

Harl::Harl()
{
	return ;
}

Harl::~Harl()
{
	return ;
}

void	Harl::debug(void) const
{
	std::cout << "[DEBUG] :"<< std::endl << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void) const
{
	std::cout << "[INFO] :"<< std::endl << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void) const
{
	std::cout << "[WARNING] :"<< std::endl << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void	Harl::error(void) const
{
	std::cout << "[ERROR] :"<< std::endl << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

int		get_level(std::string level)
{
	const std::string	name[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i=0; i < 4; i++)
	{
		if (name[i] == level)
			return (i);
	}
	return(42);
}

void	Harl::complain(std::string level)
{
	const func_ptr list[4] = {&Harl::debug,&Harl::info, &Harl::warning, &Harl::error};
	int				lvl = get_level(level);

	(this->*(list[lvl]))();
}

