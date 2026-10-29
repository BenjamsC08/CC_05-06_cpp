#ifndef RPN_HPP
# define RPN_HPP

# include <string>

class RPN
{
public:
	RPN();
	RPN(const char * );
	RPN(const RPN &  );
	~RPN();

	RPN &operator=(const RPN &);

	static void	calculate(std::string &);
	static void calculate(const char * );

	class BadExpressionException : public std::exception {
		public:
			virtual const char *what() const throw();
	};

protected:
	static bool	verify_expression(std::string  );

private:
};

#endif
