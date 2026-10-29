#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl
{
	private:
		void	debug(void) const;
		void	info(void) const;
		void	warning(void) const;
		void	error(void) const;
	
	public:
		Harl();
		~Harl();
		void	complain(std::string level);
};

typedef void  (Harl::*func_ptr)(void) const;
int			  get_level(std::string level);

#endif
