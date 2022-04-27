/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:13:30 by jmilhas           #+#    #+#             */
/*   Updated: 2022/04/27 13:51:48 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
# define SIGN_GRADE 145
# define EXEC_GRADE 137
# define FORM_NAME "shrubberyCreation"

ShrubberyCreationForm::ShrubberyCreationForm(void):
	Form(FORM_NAME, SIGN_GRADE, EXEC_GRADE), _target("No target"){
	/* std::cout << "Default constructor called" << std::endl; */
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target):
	Form(FORM_NAME, SIGN_GRADE, EXEC_GRADE), _target(target){
	/* std::cout << "Default constructor called" << std::endl; */
	return ;
}



ShrubberyCreationForm::~ShrubberyCreationForm(void){
	/* std::cout << "Destructor called" << std::endl; */
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &shrubbery):
	Form(FORM_NAME, SIGN_GRADE, EXEC_GRADE){
	/* std::cout << "Copy constructor called" << std::endl; */
	*this = shrubbery;
	return;
}
ShrubberyCreationForm &ShrubberyCreationForm::operator = (const ShrubberyCreationForm &shrubbery){
	if (&shrubbery != this){
		this->_target = shrubbery._target;
	}
	return (*this);
}

std::string	ShrubberyCreationForm::getTarget(void)const{
	return (this->_target);
}

void	ShrubberyCreationForm::executeAction(void)const{
	std::string filename = getTarget() + "_shrubbery";
	std::ofstream File_shrub(filename.c_str());
	if (!File_shrub.is_open()){
		std::cerr << "Can't open file error" << std::endl;
		return ;
	}
	File_shrub
		<< "				,@@@@@@@, " << std::endl
		<< "		,,,.   ,@@@@@@/@@,  .oo8888o. " << std::endl
		<< "		,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o " << std::endl
		<< "	,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88' " << std::endl
		<< "	%&&%&%&/%&&%@@\\@@/ /@@@88888\\88888' " << std::endl
		<< "	%&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88' " << std::endl
		<< "	`&%\\ ` /%&'    |.|        \\ '|8' " << std::endl
		<< "	|o|        | |         | | " << std::endl
		<< "		|.|        | |         | | " << std::endl
		<< "		\\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
	File_shrub.close();
}


