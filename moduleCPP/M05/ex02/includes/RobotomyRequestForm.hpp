#ifndef ROBOTOMY_CREATION_FORM_HPP
# define ROBOTOMY_CREATION_FORM_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>

# include "Form.hpp"

# define C_RED "\033[1;31m"
# define C_GREEN "\033[1;32m"
# define C_END "\033[0m"

class Form;

class RobotomyRequestForm : public Form {

private:
	std::string _target;
	
public:
	RobotomyRequestForm();
	~RobotomyRequestForm();
    RobotomyRequestForm (const RobotomyRequestForm &RobotomyRequestForm);
    RobotomyRequestForm (const std::string &target);
    RobotomyRequestForm & operator= (const RobotomyRequestForm &RobotomyRequestForm);

	std::string getTarget() const;
	void executeAction() const;

};

#endif

