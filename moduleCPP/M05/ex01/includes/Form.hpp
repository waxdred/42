#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <stdlib.h>

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

private:
	const std::string _name;
	const int _gradeToSign;
	const int _gradeToExecute;
	bool _isSigned;
	
public:
	Form();
	~Form();
    Form (const Form &form);
    Form (const std::string &name, const int &gradeToSign, const int &gradeToExecute);
    Form & operator= (const Form &form);

	const std::string getName() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	bool getIsSigned() const ;

	void beSigned(const Bureaucrat &bureaucrat);

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

std::ostream & operator<< (std::ostream & o, Form const & form);

#endif

