
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm(std::string);
	PresidentialPardonForm(const PresidentialPardonForm &);
	~PresidentialPardonForm();
	PresidentialPardonForm &operator=(const PresidentialPardonForm &);

	void			  beSigned(Bureaucrat &);
	void			  execute(const Bureaucrat &) const;

};

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &src);
