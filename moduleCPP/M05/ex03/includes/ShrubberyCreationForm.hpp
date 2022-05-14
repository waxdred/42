#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include <iostream>
# include <fstream>

# include "Form.hpp"

class Form;

class ShrubberyCreationForm : public Form {

private:
	std::string _target;
	
public:
	ShrubberyCreationForm();
	~ShrubberyCreationForm();
    ShrubberyCreationForm (const ShrubberyCreationForm &shrubberyCreationForm);
    ShrubberyCreationForm (const std::string &target);
    ShrubberyCreationForm & operator= (const ShrubberyCreationForm &shrubberyCreationForm);

	std::string getTarget() const;
	void executeAction() const;

};

#endif

