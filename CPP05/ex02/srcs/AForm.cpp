
#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExec(150)
{
	if (DISP_DEBUG == 1)
		std::cout << "AForm Default Constructor" << std::endl;
}

AForm::AForm(std::string name) : _name(name), _isSigned(false), _gradeToSign(150), _gradeToExec(150)
{
	if (DISP_DEBUG == 1)
		std::cout << "AForm Default Constructor" << std::endl;
}

AForm::AForm(int gradeToSign, int gradeToExec) :
	_name("default"), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (DISP_DEBUG == 1)
		std::cout << "AForm Default Constructor" << std::endl;
	if (_gradeToSign < 1 || _gradeToExec < 1)
		throw AForm::GradeTooHighException();
	if (_gradeToExec > 150 || _gradeToSign > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExec) :
	_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (DISP_DEBUG == 1)
		std::cout << "AForm Default Constructor" << std::endl;
	if (_gradeToSign < 1 || _gradeToExec < 1)
		throw AForm::GradeTooHighException();
	if (_gradeToExec > 150 || _gradeToSign > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other) :
	_name(other._name), _isSigned(false), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec)
{
	if (DISP_DEBUG == 1)
		std::cout << "AForm Copy Constructor" << std::endl;
}

AForm::~AForm()
{
	if (DISP_DEBUG == 1)
		std::cout << "AForm Default Destructor" << std::endl;
}

// Methods

// void  AForm::setFormSigned()
// {
// 	this->_isSigned = true;
// }

void AForm::beSigned(Bureaucrat &employee)
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


// Accessors

const std::string AForm::getName() const
{
	return (this->_name);
}

bool		  AForm::isSigned() const
{
	return (this->_isSigned);
}

int		  AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int		  AForm::getGradeToExec() const
{
	return (this->_gradeToExec);
}

// Exception

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return (RED "Grade too high" RESET);
};

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return (RED "Grade too low" RESET);
};

const char *AForm::FormNotSigned::what(void) const throw()
{
	return (RED "Need to sign Form before trying to execute" RESET);
};


// stream

std::ostream &operator<<(std::ostream &out, const AForm &src)
{
	out << CYAN << src.getName() << "'s AForm, grade to sign " << src.getGradeToSign() << ",";
	out << " and " << src.getGradeToExec() << " to execute the form " <<  "." << RESET;
	return (out);
}


