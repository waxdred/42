#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include <iostream>

# include "Form.hpp"

# define C_RED "\033[1;31m"
# define C_GREEN "\033[1;32m"
# define C_END "\033[0m"

class Form;

class PresidentialPardonForm : public Form {

private:
	std::string _target;
	
public:
	PresidentialPardonForm();
	~PresidentialPardonForm();
    PresidentialPardonForm (const PresidentialPardonForm &presidentialPardonForm);
    PresidentialPardonForm (const std::string &target);
    PresidentialPardonForm & operator= (const PresidentialPardonForm &presidentialPardonForm);

	std::string getTarget() const;
	void executeAction() const;

};

#endif

