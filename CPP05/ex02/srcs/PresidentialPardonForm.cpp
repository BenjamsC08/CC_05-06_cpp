#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "def.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string name) : AForm(name, 25, 5)
{
	if (DISP_DEBUG == 1)
		std::cout << "RobotomyForm Default Constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other.getName(), other.getGradeToSign(), other.getGradeToExec())
{
	if (DISP_DEBUG == 1)
		std::cout << "RobotomyForm Copy Constructor" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (DISP_DEBUG == 1)
		std::cout << "RobotomyForm Assignement " << std::endl;
	if (this != &other)
	{
		this->~PresidentialPardonForm();
		new (this) PresidentialPardonForm(other);
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	if (DISP_DEBUG == 1)
		std::cout << "RobotomyForm Default Destructor" << std::endl;
}

void PresidentialPardonForm::execute(const Bureaucrat &employee) const
{
	if (!this->isSigned())
		throw AForm::FormNotSigned();
	if (employee.getGrade() > this->getGradeToExec())
	{
		std::cout << ORANGE << employee.getName() << " couldn’t execute '" << this->getName() << "' because ";
		std::cout << "grade to low " << employee.getGrade() << " but required " << this->getGradeToExec() << std::endl << RESET;
	}
	else
	{
		std::cout << MAGENTA << employee.getName() << " executed " << this->getName() << RESET << std::endl;
		std::cout << CYAN << employee.getName() << " has been pardoned by Zaphod Beeblebrox.\n" << RESET;
	}
}

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &src)
{
	out << "Form : "<< YELLOW << "'" << YELLOW << src.getName() << "' a PresidentialPardonForm, grade to sign {" << src.getGradeToSign() << "},";
	out << " and {" << src.getGradeToExec() << "} to execute the form " <<  "." << RESET;
	return (out);
}

