#ifndef SPAN_HPP
# define SPAN_HPP
#include "def.hpp"

#include <set>


class Span
{
	public :
		Span(t_uint);
		Span(const Span &);
		Span &operator=(const Span &);
		~Span();

		void	addNumber(int balue);
		void	addNumber(int begin, int end, t_uint step = 1);
		t_uint		shortestSpan();
		t_uint		longestSpan();

	private :
		Span();

		t_uint				_size;
		std::multiset<int>	_tab;

};
#endif
