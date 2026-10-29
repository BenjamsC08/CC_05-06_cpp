
#include "AForm.hpp"
#include <string>

class Intern
{
public:
	Intern();
	Intern(const Intern &);
	~Intern();
	Intern &operator=(const Intern &);

	AForm *makeForm(std::string , std::string);
	typedef void  (Intern::*func_ptr)(void) const;
	class ReadException : public std::exception {
		public:
			virtual const char *what() const throw();
	};

};


