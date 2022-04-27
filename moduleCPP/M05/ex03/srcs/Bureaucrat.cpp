/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:19:51 by jmilhas           #+#    #+#             */
/*   Updated: 2022/04/27 13:44:19 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("Anonymous"){
	/* std::cout << "Default constructor called" << std::endl; */
	std::srand(time(0));
	this->_grade = (std::rand() % 151);
	return ;
}

Bureaucrat::Bureaucrat(const std::string name): _name(name){
	std::srand(time(0));
	this->_grade = (std::rand() % 151);
	return;
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name){
	if (grade < 1)
		throw Bureaucrat::GradeTooLowExeption();
	else if (grade > 150)
		throw Bureaucrat::GradeTooHightExeption();
	this->_grade = grade;
	return;
}

Bureaucrat::Bureaucrat(int grade): _name("Anonymous"){
	if (grade < 1)
		throw Bureaucrat::GradeTooLowExeption();
	else if (grade > 150)
		throw Bureaucrat::GradeTooHightExeption();
	this->_grade = grade;
	return;
}

Bureaucrat::~Bureaucrat(void){
	/* std::cout << "Destructor called" << std::endl; */
	return ;
}


Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat){
	/* std::cout << "Copy constructor called" << std::endl; */
	*this = bureaucrat;
	return;
}

Bureaucrat &Bureaucrat::operator = (const Bureaucrat &bureaucrat){
	if (&bureaucrat != this)
	{
		this->_grade = bureaucrat._grade;
	}
	return (*this);
}

int	Bureaucrat::getGrade(void)const{
	return (this->_grade);
}

const std::string Bureaucrat::getName(void)const{
	return (this->_name);
}

// class expection
const char *Bureaucrat::GradeTooHightExeption::what() const throw(){
	return ("Grade to hight!");
}

const char *Bureaucrat::GradeTooLowExeption::what() const throw(){
	return ("Grade to low!");
}

//output value pof the class
std::ostream &operator << (std::ostream &o, const Bureaucrat &s){
	o << s.getName() << ": Grade: " << s.getGrade() << std::endl;
	return (o);
}

void Bureaucrat::signForm(Form &f){
	if (f.getSign())
		std::cout << this->_name << " cannot sign " << f.getName() << "because " << std::endl;
	else
		std::cout << this->_name << " couldn't sign" << f.getName() << "because is grade is to low" << std::endl;
}

void Bureaucrat::executeForm(Form const & form) {
	try {
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	} catch (std::exception& e) {
		std::cout << _name << " cant’t execute " << form.getName() << " because... " << e.what() << std::endl;
	}

}


void Bureaucrat::decrementeGrade(void){
	if (this->_grade > 149)
		throw Bureaucrat::GradeTooHightExeption();
	else
		this->_grade++;
}

void Bureaucrat::incrementeGrade(void){
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooLowExeption();
	else
		this->_grade--;
}
