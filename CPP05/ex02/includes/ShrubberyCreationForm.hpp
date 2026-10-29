
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{

public:
	ShrubberyCreationForm(std::string);
	ShrubberyCreationForm(const ShrubberyCreationForm &);
	~ShrubberyCreationForm();
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &);

	void			  execute(const Bureaucrat &) const;

};

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &src);
