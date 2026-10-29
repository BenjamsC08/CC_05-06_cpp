#pragma once


#include <iostream>
#include "def.hpp"

class AForm;

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
		void			  promote(int);
		void			  demote();
		void			  demote(int);

		void			  signForm(AForm &);
		void			  executeForm(const AForm &) const;

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

