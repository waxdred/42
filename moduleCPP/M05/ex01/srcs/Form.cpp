/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:53:18 by jmilhas           #+#    #+#             */
/*   Updated: 2022/04/22 15:02:41 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string const name, int const signGrade, int const execGrade){

	return ;
}

Form::~Form(void){
	/* std::cout << "Destructor called" << std::endl; */
	return ;
}

Form::Form(const Form &form){
	/* std::cout << "Copy constructor called" << std::endl; */
	*this = form;
	return;
}
Form &Form::operator = (const Form &form){
	if (&form != this)
	{
		this->_sign = form._sign;
	}
	return (*this);
}

std::string	Form::getName(void)const{
	return (this->_name);
}

bool	Form::getSign(void)const{
	return (this->_sign);
}

int	Form::getSignGrade(void)const{
	return (this->_signGrade);
}

int	Form::getExecGrade(void)const{
	return (this->_execGade);
}

std::ostream &operator<<(std::ostream &o, Form const &form)
{
	o << "(" << form.getName() << ")[" << ((form.getSign()) ? "Signed" : "Unsigned")
		<< "]<Sign:" << form.getSignGrade() << ",Execute:"
		<< form.getExecGrade() << ">";
	return (o);
}
