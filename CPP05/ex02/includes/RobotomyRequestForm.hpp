
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{

public:
	RobotomyRequestForm(std::string);
	RobotomyRequestForm(const RobotomyRequestForm &);
	~RobotomyRequestForm();
	RobotomyRequestForm &operator=(const RobotomyRequestForm &);

	void			  beSigned(Bureaucrat &);
	void			  execute(const Bureaucrat &) const;

};

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &src);
