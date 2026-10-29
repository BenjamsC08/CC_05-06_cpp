
#include <cstddef>
#include <list>
#include <sstream>
#include <stdexcept>

template <typename T>
class ListIdx : public std::list<T>
{
public:
    ListIdx();
    ListIdx(const ListIdx &);
    ~ListIdx();
    
    ListIdx	&operator=(const ListIdx &);

	typedef typename std::list<T>::iterator iterator;
    iterator	dxBegin() { return this->begin(); }
    iterator	dxEnd()   { return this->end();   }

	typedef typename std::list<T>::const_iterator const_iterator;
	const_iterator	cbegin() const { return this->begin(); }
	const_iterator	cend()   const { return this->end();   }

    T		&operator[](const size_t);
    const T	&operator[](const size_t) const;

	T	&at(size_t);   
};



template <typename T>
ListIdx<T>::ListIdx() : std::list<T>() {}

template <typename T>
ListIdx<T>::ListIdx(const ListIdx &other) : std::list<T>(other) {}

template <typename T>
ListIdx<T>::~ListIdx() {}

template <typename T>
ListIdx<T>	&ListIdx<T>::operator=(const ListIdx &other)
{
	if (this != &other)
		std::list<T>::operator=(other);
	return *this;
}

template <typename T>
T	&ListIdx<T>::operator[](const size_t n)
{ 
	if (n >= this->size())
	{
		std::ostringstream s;
		s << "Vector::_M_range_check: __n (which is " << n << ") >=";
		s << "this->size() (which is " << this->size() << ")";
		throw std::out_of_range(s.str());
	}

	iterator it = this->dxBegin();
	size_t i = 0;
	for (; it != this->dxEnd(); it++)
	{
		if (i == n)
			return (*it);
		i++;
	}
	return (*this->dxEnd());

};

template <typename T>
const T	&ListIdx<T>::operator[](const size_t n) const
{ 
	if (static_cast<size_t>(n) >= this->size())
	{
		std::ostringstream s;
		s << "Vector::_M_range_check: __n (which is " << n << ") >=";
		s << "this->size() (which is " << this->size() << ")";
		throw std::out_of_range(s.str());
	}

	const_iterator it = this->cbegin();
	size_t i = 0;
	for (; it != this->cend(); it++)
	{
		if (i == n)
			return (*it);
		i++;
	}
	return (*this->cend());
};

template <typename T>
T	&ListIdx<T>::at(size_t n)
{
	if (n >= this->size())
	{
		std::ostringstream s;
		s << "Vector::_M_range_check: __n (which is " << n << ") >=";
		s << "this->size() (which is " << this->size() << ")";
		throw std::out_of_range(s.str());
	}

	iterator it = this->begin();

	while (it != this->end())
	{
		if (n == 0)
			break ;
		n--;
		it++;
	}
	return (*it);
}
