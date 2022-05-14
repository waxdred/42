#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdlib.h>
# include <ctime>

# include "Form.hpp"

class Form;

class Bureaucrat {

private:
	const std::string _name;
	int _grade;
	
public:
	Bureaucrat();
	~Bureaucrat();
    Bureaucrat (const Bureaucrat &bureaucrat);
    Bureaucrat (const std::string &name);
    Bureaucrat (const std::string &name, const int &grade);
    Bureaucrat (const int &grade);
    Bureaucrat & operator= (const Bureaucrat &bureaucrat);

	const std::string getName() const ;
	int getGrade() const ;

	void incrementGrade();
	void incrementGrade(const int &grade) ;
	void decrementGrade();
	void decrementGrade(const int &grade) ;

	void signForm(Form& form);
	void executeForm(Form const & form);

	class GradeTooHighException : public std::exception
	{
		public:
			 char const* what() const throw ();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			 char const* what() const throw ();
	};
};

std::ostream & operator<< (std::ostream & o, Bureaucrat const & bureaucrat);

#endif

