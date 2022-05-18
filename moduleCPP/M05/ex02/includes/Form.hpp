/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:50:10 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/16 13:50:23 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	virtual ~Form();
	Form (const Form &form);
	Form (const std::string &name, const int &gradeToSign, const int &gradeToExecute);
	Form & operator= (const Form &form);

	const std::string getName() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	bool getIsSigned() const ;

	void beSigned(const Bureaucrat &bureaucrat);

	void execute(Bureaucrat const & bureaucrat) const;
	virtual void executeAction() const = 0;

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
	class FormNotSignException : public std::exception
	{
		public:
			 char const* what() const throw ();
	};
};

std::ostream & operator<< (std::ostream & o, Form const & form);

#endif

