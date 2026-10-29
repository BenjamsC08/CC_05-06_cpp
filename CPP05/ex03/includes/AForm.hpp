
#pragma once

#include <iostream>
#include "def.hpp"
#include "Bureaucrat.hpp"

// class Bureaucrat;

class AForm
{
public:
	AForm();
	AForm(std::string);
	AForm(int, int);
	AForm(std::string, int, int);
	AForm(const AForm &);
	virtual ~AForm();

	// methods
	void					  beSigned(Bureaucrat &);
	virtual void			  execute(const Bureaucrat &) const = 0;
	// Accessors
	const std::string getName() const;
	int				  getGradeToSign() const;
	int				  getGradeToExec() const;
	bool			  isSigned() const;

	void			  setFormSigned();


	class GradeTooHighException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
	class FormNotSigned : public std::exception {
		public:
			virtual const char *what() const throw();
	};

private:
		const std::string _name;
		bool			  _isSigned;
		const int		  _gradeToSign;
		const int		  _gradeToExec;

};

std::ostream& operator<<(std::ostream &out, const AForm &src);
