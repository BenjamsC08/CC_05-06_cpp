#include <climits>
#include <cstdlib>
#include <iostream>
#include <stack>

#include "def.hpp"
#include "RPN.hpp"

RPN::RPN()	{}

RPN::RPN(const RPN &other)	{	(void)other;  }

RPN::~RPN()	{}

RPN	&RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		this->~RPN();
		new (this) RPN(other);
	}
	return (*this);
}

int	get_level(char c, std::string &charset)
{	return (charset.find(c));	}

void	RPN::calculate(std::string &s)
{
	if (!verify_expression(s))
		throw RPN::BadExpressionException();
	
	std::stack<int> stash;
	std::string op = "-+*/";

	for (t_uint i=0; i < s.length(); i+=2)
	{
		if (op.find_first_of(s[i]) == std::string::npos)
			stash.push(atoi(&s[i]));
		else
		{
			if (stash.empty())
				throw RPN::BadExpressionException();
			
			int top0 = stash.top();
			stash.pop();
			if (stash.empty())
				throw RPN::BadExpressionException();
			
			int top1 = stash.top();
			stash.pop();
			int k = get_level(s[i], op);
			switch (k) {
				case 0:
					if ((top0 == INT_MIN || top1 == INT_MIN) && (top0 > 0 || top1 > 0))
						throw std::runtime_error(RED "Error: Overflow" RESET);
					if ((top0 == INT_MAX || top1 == INT_MAX) && (top0 < 0 || top1 < 0))
						throw std::runtime_error(RED "Error: Overflow" RESET);
					top1 -= top0;
					break ;
				case 1:
					if ((top0 == INT_MIN || top1 == INT_MIN) && (top0 < 0 || top1 < 0))
						throw std::runtime_error(RED "Error: Overflow" RESET);
					if ((top0 == INT_MAX || top1 == INT_MAX) && (top0 > 0 || top1 > 0))
						throw std::runtime_error(RED "Error: Overflow" RESET);
					top1 += top0;
					break ;
				case 2:
					if ((top0 == INT_MIN || top1 == INT_MIN) && (top0 < 0 || top1 < 0))
						throw std::runtime_error(RED "Error: Overflow" RESET);
					top1 *= top0;
					break ;
				case 3:
					if (top0 == 0)
						throw std::runtime_error(RED "Error: division by zero" RESET);
					if ((top0 == INT_MIN || top1 == INT_MIN) && (top0 == -1 || top1 == -1))
						throw std::runtime_error(RED "Erro: Overflow" RESET);
					top1 /= top0;
					break ;
			}
			stash.push(top1);
		}
	}
	std::cout << stash.top() << '\n';
	stash.pop();
	return;
}

void	RPN::calculate(const char *strc)
{
	if (!strc)
		throw RPN::BadExpressionException();
	std::string s = strc;
	return (calculate(s));
}

bool	RPN::verify_expression(std::string s)
{
	if (s.empty() || s.find_first_not_of(" 0123456789+-/*") != std::string::npos)
		return false;
	bool ws = true;
	for (t_uint i=0; i < s.length(); i++)
	{
		if (ws == (s[i] == ' ')) 
			return false;
		ws = (s[i] == ' ');
	}
	return true;
}

const char	*RPN::BadExpressionException::what(void) const throw()
{
	return (RED "Error: Expression not accepted" RESET);
};


