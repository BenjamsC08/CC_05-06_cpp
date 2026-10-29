#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <ostream>

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (DISP_DEBUG == 1)
		std::cout << "Bureaucrat Default Constructor" << std::endl;
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
	if (DISP_DEBUG == 1)
		std::cout << "Bureaucrat Copy Constructor" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (DISP_DEBUG == 1)
		std::cout << "Bureaucrat Assignement " << std::endl;
	if (this != &other)
	{
		this->~Bureaucrat();
		new (this) Bureaucrat(other);
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	if (DISP_DEBUG == 1)
		std::cout << "Bureaucrat Destructor" << std::endl;
}


int Bureaucrat::getGrade() const
{
	return (_grade);
}

const std::string Bureaucrat::getName() const
{
	return (_name);	
}

void Bureaucrat::demote()
{
	std::cout << YELLOW << "try to demote " << this->getName() << " to grade " << this->getGrade() + 1 << std::endl;
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
	std::cout << "     - succeed\n" << RESET;
}

void Bureaucrat::demote(int to)
{
	std::cout << YELLOW << "try to demote " << this->getName() << " to grade " << to << std::endl;
	if (this->_grade + to >= 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = to;
	std::cout << "     - succeed\n" << RESET;
}


void Bureaucrat::promote()
{
	std::cout << GREEN << "try to promote " << this->getName() << " to grade " << this->getGrade() - 1 << std::endl;
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
	std::cout << "     - succeed\n" << RESET;
}

void Bureaucrat::promote(int to)
{
	std::cout << GREEN << "try to promote " << this->getName() << " to grade " << to << std::endl;
	if (this->_grade - to <= 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = to;
	std::cout << "     - succeed\n" << RESET;
}


void  Bureaucrat::signForm(AForm &form)
{
	form.beSigned(*this);
}

void  Bureaucrat::executeForm(const AForm &form) const
{
	form.execute(*this);
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return (RED "Grade too high" RESET);
};

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return (RED "Grade too low" RESET);
};


std::ostream &operator<<(std::ostream &out, const Bureaucrat &src)
{
	out << CYAN << src.getName() << ", bureaucrat grade " << src.getGrade() << "." << RESET;
	return (out);
}

