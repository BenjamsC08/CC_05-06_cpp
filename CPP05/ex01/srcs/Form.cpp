
#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExec(150)
{
	if (DISP_DEBUG == 1)
		std::cout << "Form Default Constructor" << std::endl;
}

Form::Form(std::string name) : _name(name), _isSigned(false), _gradeToSign(150), _gradeToExec(150)
{
	if (DISP_DEBUG == 1)
		std::cout << "Form Default Constructor" << std::endl;
}

Form::Form(int gradeToSign, int gradeToExec) :
	_name("default"), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (DISP_DEBUG == 1)
		std::cout << "Form Default Constructor" << std::endl;
	if (_gradeToSign < 1 || _gradeToExec < 1)
		throw Form::GradeTooHighException();
	if (_gradeToExec > 150 || _gradeToSign > 150)
		throw Form::GradeTooLowException();
}

Form::Form(std::string name, int gradeToSign, int gradeToExec) :
	_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (DISP_DEBUG == 1)
		std::cout << "Form Default Constructor" << std::endl;
	if (_gradeToSign < 1 || _gradeToExec < 1)
		throw Form::GradeTooHighException();
	if (_gradeToExec > 150 || _gradeToSign > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &other) :
	_name(other._name), _isSigned(false), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec)
{
	if (DISP_DEBUG == 1)
		std::cout << "Form Copy Constructor" << std::endl;
}

Form &Form::operator=(const Form &other)
{
	if (DISP_DEBUG == 1)
		std::cout << "Form Assignement " << std::endl;
	if (this != &other)
	{
		this->~Form();
		new (this) Form(other);
	}
	return (*this);
}

Form::~Form()
{}

// Mehtods

void Form::beSigned(Bureaucrat &employee)
{
	if (employee.getGrade() > this->getGradeToSign())
	{
		std::cout << ORANGE << employee.getName() << " couldn’t sign '" << this->getName()  << "' because ";
		std::cout << "grade to low " << employee.getGrade() << " but require " << this->getGradeToSign() << std::endl << RESET;
	}
	else
	{
		this->_isSigned = true;
		std::cout << GREEN << employee.getName() << " signed '" << this->getName() << "'" << std::endl << RESET;
	}
}

void Form::execForm(Bureaucrat &employee)
{
	if (employee.getGrade() > this->getGradeToExec())
	{
		std::cout << ORANGE << employee.getName() << " couldn’t exec '" << this->getName()  << "' because ";
		std::cout << "grade to low " << employee.getGrade() << " but require " << this->getGradeToExec() << std::endl << RESET;
	}
	else
	{
		this->_isSigned = true;
		std::cout << GREEN << employee.getName() << " execute '" << this->getName() << "'" << std::endl << RESET;
	}
}

// Accessors

const std::string Form::getName() const
{
	return (this->_name);
}

bool		  Form::isSigned() const
{
	return (this->_isSigned);
}

int		  Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int		  Form::getGradeToExec() const
{
	return (this->_gradeToExec);
}

// Exception

const char *Form::GradeTooHighException::what(void) const throw()
{
	return (RED "Grade too high" RESET);
};

const char *Form::GradeTooLowException::what(void) const throw()
{
	return (RED "Grade too low" RESET);
};

// stream

std::ostream &operator<<(std::ostream &out, const Form &src)
{
	out << CYAN << src.getName() << "'s Form, grade to sign " << src.getGradeToSign() << ",";
	out << " and " << src.getGradeToExec() << " to execute the form " <<  "." << RESET;
	return (out);
}


