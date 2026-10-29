#include <cstdlib>
#include <iostream>
#include <list>

#include "def.hpp"
#include "MutantStack.hpp"

#define INT_MAX 2147483647

int mainList();

int main()
{
	mainList();
	std::cout << RED << "Mutant Stack:\n" << RESET;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);

	std::cout << "stack top: " << mstack.top() << '\n';

	std::cout << "stack size before pop: " << mstack.size() << '\n';
	mstack.pop();

	std::cout << "stack size after pop: " << mstack.size() << '\n';

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	// for (size_t i=0; i < 10; i++)
	// 		mstack.push(rand() % INT_MAX);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	std::cout << GREEN << "Mutant stack it:\n" << RESET;
	while (it != ite)
	{
		std::cout << *it << '\n';
		++it;
	}

	std::cout << RED << "Stack:\n" << RESET;
	std::stack<int> s(mstack);
	std::cout << BLUE << "Normal stack it:\n" RESET;
	while (s.size() > 0)
	{
		std::cout << s.top() << '\n';
		s.pop();
	}
	return 0;
}

int mainList()
{
	std::cout << RED << "List:\n" << RESET;
	std::list<int> l;
	l.push_back(5);
	l.push_back(17);

	std::cout << "list top: " << l.back() << '\n';

	std::cout << "list size before pop: " << l.size() << '\n';
	l.pop_back();

	std::cout << "list size after pop: " << l.size() << '\n';

	l.push_back(3);
	l.push_back(5);
	l.push_back(737);
	// for (size_t i=0; i < 10; i++)
	// 		l.push_back(rand() % INT_MAX);
	l.push_back(0);

	std::list<int>::iterator it = l.begin();
	std::list<int>::iterator ite = l.end();

	++it;
	--it;

	std::cout << GREEN << "list it:\n" << RESET;
	while (it != ite)
	{
		std::cout << *it << '\n';
		++it;
	}
	return (1);
}
