
#include <cstdlib>
#include <ctime>
#include "RobotomyRequestForm.hpp"
#include "def.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string name) : AForm(name, 72, 45)
{
	if (DISP_DEBUG == 1)
		std::cout << "RobotomyForm Default Constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other.getName(), other.getGradeToSign(), other.getGradeToExec())
{
	if (DISP_DEBUG == 1)
		std::cout << "RobotomyForm Copy Constructor" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (DISP_DEBUG == 1)
		std::cout << "RobotomyForm Assignement " << std::endl;
	if (this != &other)
	{
		this->~RobotomyRequestForm();
		new (this) RobotomyRequestForm(other);
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	if (DISP_DEBUG == 1)
		std::cout << "RobotomyForm Default Destructor" << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat &employee) const
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
		std::cout << CYAN << "DRrrrrrrrrrrrrrrrrrrrRRRrrrrrr\n" << "DRrrrrrrrrrrrrrrrrrrrRRRrrrrrr\n" << "DRrrrrrrrrrrrrrrrrrrrRRRrrrrrr\n" << RESET;
		srand(time(0));
		int r = rand() % 2;
		if (DISP_DEBUG == 2)
			std::cout << r << std::endl;
		if (r % 2 == 0)
			std::cout << GREEN << this->getName() << "has been robotomized\n" << RESET;
		else
			std::cout << ORANGE << "failed robotomy for " << this->getName() << RESET << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &src)
{
	out  << "Form : " << BLUE << "'" << src.getName() << "' a RobotomyRequestForm, grade to sign {" << src.getGradeToSign() << "},";
	out << " and {" << src.getGradeToExec() << "} to execute the form " <<  "." << RESET;
	return (out);
}

