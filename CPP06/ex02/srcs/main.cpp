
#include "C.hpp"

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

int main()
{
	Base *t;

	t = generate();
	identify(t);
	std::cout << std::endl;

	identify(*t);
	delete t;
	std::cout << std::endl << std::endl;

	return (0);
}
