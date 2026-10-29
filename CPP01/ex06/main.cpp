
#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong usage for complaining ./harlFilter <LEVEL>" << std::endl;
		return(1);
	}

	Harl	harl;
	int		lvl = get_level(argv[1]);
	
	switch(lvl)
	{
		case 0 :
			harl.complain("DEBUG");
		case 1 :
			harl.complain("INFO");
		case 2 :
			harl.complain("WARNING");
		case 3 :
			harl.complain("ERROR");
			break ;
		default :
			std::cout << "[Probably complaining about insignificant problems]" << std::endl;
	}
	return (0);
}
