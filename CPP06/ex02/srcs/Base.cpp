#include "C.hpp"
#include <cstdlib>
#include <exception>

// class Base; 
// class A; 
// class B; 
// class C; 

Base *generate(void)
{
	srand(time(0));
	int randomNum = rand() % 3;
	Base *obj;

	switch (randomNum)
	{
		case 0:
			std::cout << CYAN "A case" << std::endl;	
			obj = new A();
			break;
		case 1:
			std::cout << CYAN "B case" RESET << std::endl;	
			obj = new B();
			break;
		case 2:
			std::cout << CYAN "C case" RESET << std::endl;
			obj = new C();
	}
	return (obj);
}

void identify(Base *p)
{
	A *t1 = dynamic_cast<A *>(p);
	if (t1 != NULL)
	{
		std::cout << GREEN "p is an A Class" RESET << std::endl;
		// delete t1;
		return;
	}
	B *t2 = dynamic_cast<B *>(p);
	if (t2 != NULL)
	{
		std::cout << GREEN "p is an B Class" RESET << std::endl;
		// delete t2;
		return;
	}
	C *t3 = dynamic_cast<C *>(p);
	if (t3 != NULL)
	{
		std::cout << GREEN "p is an C Class" RESET << std::endl;
		// delete t3;
		return;
	}
}

void identify(Base &p)
{
	try
	{
		(void) dynamic_cast<A&>(p);
		std::cout << GREEN "p is an A Class" RESET << std::endl;
		return;
	}
	catch (std::exception &err)
	{
		std::cout << RED "p is NOT an A Class" RESET << std::endl;
	}
	try
	{
		(void) dynamic_cast<B&>(p);
		std::cout << GREEN "p is an B Class" RESET << std::endl;
		return;
	}
	catch (std::exception &err)
	{
		std::cout << RED "p is NOT an B Class" RESET << std::endl;
	}
	try
	{
		(void) dynamic_cast<C&>(p);
		std::cout << GREEN "p is an C Class" RESET << std::endl;
		return;
	}
	catch (std::exception &err)
	{
		std::cout << RED "p is NOT an C Class" RESET << std::endl;
	}
}
