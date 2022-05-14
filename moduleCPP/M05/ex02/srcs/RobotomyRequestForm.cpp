/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 08:51:08 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/14 08:51:21 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

# define SIGN_GRADE 72
# define EXEC_GRADE 45
# define FORM_NAME "robotomyRequest"

RobotomyRequestForm::RobotomyRequestForm() :
	Form (FORM_NAME, SIGN_GRADE, EXEC_GRADE),
	_target("No specific target")
{
	//std::cout << "[ROBOTOMYREQUESTFORM] Default constructor called" << std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :
	Form (FORM_NAME, SIGN_GRADE, EXEC_GRADE),
	_target(target)
{
	//std::cout << "[ROBOTOMYREQUESTFORM] Default constructor called" << std::endl;
	return;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	//std::cout << "[ROBOTOMYREQUESTFORM] Destructor called" << std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &robotomyRequestForm) :
	Form (FORM_NAME, SIGN_GRADE, EXEC_GRADE)
{
	//std::cout << "[ROBOTOMYREQUESTFORM] Copy constructor called" << std::endl;
	*this = robotomyRequestForm;
	return;
}

RobotomyRequestForm & RobotomyRequestForm::operator= (const RobotomyRequestForm &robotomyRequestForm) {
	//std::cout << "[ROBOTOMYREQUESTFORM] Copy assignment operator called" << std::endl;
	if (this != &robotomyRequestForm) {
		_target = robotomyRequestForm.getTarget();
	}
	return (*this);
}

std::string RobotomyRequestForm::getTarget() const {
	return (this->_target);
}

void RobotomyRequestForm::executeAction() const {
	std::srand(time(0));
	bool success = std::rand() % 2;

	std::cout << "* zZzzzZZZZzzZZZz PIIIIII PPOOOO TUCTUCTZZZZZZZ *" << std::endl;
	if (success)
		std::cout << C_GREEN << getTarget() << " has been robotomized successfully!" << C_END << std::endl;
	else
		std::cout << C_RED << getTarget() << " died in the operation!" << C_END << std::endl;
}
