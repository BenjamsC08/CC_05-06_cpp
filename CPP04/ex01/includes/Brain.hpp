
# pragma once
# include <iostream>
#include "def.hpp"

class Brain
{
	public:
		Brain();
		Brain(const Brain &);
		Brain &operator=(const Brain &);
		virtual ~Brain();

	protected:
		std::string _ideas[100];

};
