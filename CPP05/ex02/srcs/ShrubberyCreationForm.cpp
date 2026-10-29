
#include <fstream>
#include <string>

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : AForm(name, 145, 137)
{
	if (DISP_DEBUG == 1)
		std::cout << "ShruberryForm Default Constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other.getName(), other.getGradeToSign(), other.getGradeToExec())
{
	if (DISP_DEBUG == 1)
		std::cout << "ShruberryForm Copy Constructor" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (DISP_DEBUG == 1)
		std::cout << "ShruberryForm Assignement " << std::endl;
	if (this != &other)
	{
		this->~ShrubberyCreationForm();
		new (this) ShrubberyCreationForm(other);
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	if (DISP_DEBUG == 1)
		std::cout << "ShruberryForm Default Destructor" << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat &employee) const
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
		std::ifstream file("assets/tree.txt");
		if (!file)
		{
			std::cerr << RED << "cannot access the sample tree\n" << RESET;
			return ;
		}
		std::string d = this->getName() + "_shrubbery";
		std::ofstream dest(d.c_str());
		dest << file.rdbuf();
		std::cout << MAGENTA << employee.getName() << " executed " << this->getName() << RESET << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &src)
{
	out  << "Form : " << MAGENTA << "'" << src.getName() << "' a ShrubberyCreationForm, grade to sign {" << src.getGradeToSign() << "},";
	out << " and {" << src.getGradeToExec() << "} to execute the form " <<  "." << RESET;
	return (out);
}

