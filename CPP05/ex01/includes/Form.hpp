
#pragma once

#include <iostream>
#include "def.hpp"

class Bureaucrat;

class Form
{
public:
	Form();
	Form(std::string);
	Form(int, int);
	Form(std::string, int, int);
	Form(const Form &);
	Form &operator=(const Form &);
	~Form();

	// methods
	void			  beSigned(Bureaucrat &);
	void			  execForm(Bureaucrat &);
	// Accessors
	const std::string getName() const;
	int				  getGradeToSign() const;
	int				  getGradeToExec() const;
	bool			  isSigned() const;


	class GradeTooHighException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
			virtual const char *what() const throw();
	};

private:
		const std::string _name;
		bool			  _isSigned;
		const int		  _gradeToSign;
		const int		  _gradeToExec;

};

std::ostream& operator<<(std::ostream &out, const Form &src);
