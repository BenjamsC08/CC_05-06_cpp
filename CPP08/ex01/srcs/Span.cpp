
#include <stdexcept>

#include "Span.hpp"

Span::Span(t_uint size) : _size(size)
{}

Span::Span(const Span &other) : _size(other._size)
{
	std::multiset<int>::iterator it;
	for (it = other._tab.begin(); it != other._tab.end(); it++)
		this->_tab.insert(*it);
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->~Span();
		new (this) Span(other);
	}
	return (*this);
}

Span::~Span()
{}

void Span::addNumber(int value)
{
	if (this->_tab.size() == this->_size)
		throw std::length_error("Too much number, does not fit into span");
	this->_tab.insert(value);
}

void Span::addNumber(int start, int end, t_uint step)
{
	for (int n=start; n <= end; n+=step)
		addNumber(n);
}

t_uint		Span::shortestSpan()
{
	if (this->_size < 2)
		throw std::length_error("Not enough int (< 2)");
	
	t_uint k = 4294967295;

	std::multiset<int>::iterator it0 = this->_tab.begin();
	for (;it0 != this->_tab.end(); it0++)
	{
		std::multiset<int>::iterator it1 = it0;
		it1++;
		if (it1 == this->_tab.end())
			break ;
		if (k > static_cast<t_uint>(*it1 - *it0))
			k = static_cast<t_uint>(*it1 - *it0);
	}
	return (k);
}

t_uint		Span::longestSpan()
{
	if (this->_size < 2)
		throw std::length_error("Not enough int (< 2)");

	std::multiset<int>::iterator it0 = this->_tab.begin();
	std::multiset<int>::iterator it1 = this->_tab.end();

	it1--;
	return (static_cast<t_uint>(*it1 - *it0));
}

