/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:19:51 by jmilhas           #+#    #+#             */
/*   Updated: 2022/04/27 11:45:13 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Anonymous") {
	//std::cout << "[BUREAUCRAT] Default constructor called" << std::endl;
	std::srand(time(0));
	_grade = 1 + (std::rand() % 150);
	return;
}

Bureaucrat::Bureaucrat(const std::string &name): _name(name) {
	//std::cout << "[BUREAUCRAT] Default constructor called" << std::endl;
	std::srand(time(0));
	_grade = 1 + (std::rand() % 150);
	return;
}

Bureaucrat::Bureaucrat(const std::string &name, const int &grade) : _name(name) {
	//std::cout << "[BUREAUCRAT] Default constructor called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
	return;
}

Bureaucrat::Bureaucrat(const int &grade) : _name("Anonymous") {
	//std::cout << "[BUREAUCRAT] Default constructor called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
	return;
}

Bureaucrat::~Bureaucrat() {
	//std::cout << "[BUREAUCRAT] Destructor called" << std::endl;
	return;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) {
	//std::cout << "[BUREAUCRAT] Copy constructor called" << std::endl;
	*this = bureaucrat;
	return;
}

Bureaucrat & Bureaucrat::operator= (const Bureaucrat &bureaucrat) {
	//std::cout << "[BUREAUCRAT] Copy assignment operator called" << std::endl;
	if (this != &bureaucrat) {
		_grade = bureaucrat.getGrade();
	}
	return (*this);
}

const std::string Bureaucrat::getName() const {
	return (this->_name);
}

int Bureaucrat::getGrade() const {
	return (this->_grade);
}


void Bureaucrat::incrementGrade(const int &grade) {
	if (_grade - grade < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade -= grade;
}

void Bureaucrat::decrementGrade(const int &grade) {
	if (_grade + grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade += grade;
}

void Bureaucrat::incrementGrade() {
	this->incrementGrade(1);
}

void Bureaucrat::decrementGrade() {
	this->decrementGrade(1);
}

char const* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Wow, too high for a grade!");
}

char const* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade can't be that low!");
}

std::ostream & operator<< (std::ostream & o, Bureaucrat const & bureaucrat) {
	o << "Bureaucrat: " <<  bureaucrat.getName() << " | Grade: " << bureaucrat.getGrade();
	return (o);
}
