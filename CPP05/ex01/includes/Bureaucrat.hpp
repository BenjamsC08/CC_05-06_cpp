#pragma once


#include <iostream>
#include "def.hpp"

class Form;

class Bureaucrat
{
	public:
		Bureaucrat(std::string, int);
		Bureaucrat(const Bureaucrat &);
		Bureaucrat &operator=(const Bureaucrat &);
		~Bureaucrat();
		
		int				  getGrade() const;
		const std::string getName() const;
		void			  promote();
		void			  demote();

		void			  signForm(Form &);

		// classes imbriquées
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
		int _grade;
	
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &src);

