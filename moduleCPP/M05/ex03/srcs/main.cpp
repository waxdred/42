/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:20:14 by jmilhas           #+#    #+#             */
/*   Updated: 2022/04/27 15:29:06 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Intern.hpp"

int main (void) {

	Bureaucrat bureaucrat("Foo", 1);
	Intern erick;
	Form *formPres;
	Form *formRobo;
	Form *formShru;
	Form *formWrong;

	std::cout << "\n===== INTERN CREATE FORMS =====" << std::endl;
	formPres = erick.makeForm("Presidential Pardon Form", "Todo");
	formRobo = erick.makeForm("Robotomy Request Form", "foo");
	formShru = erick.makeForm("Shrubbery Creation Form", "Garden");
	try{
		formWrong = erick.makeForm("Wrong Creation Form", "WrongGuy");
	}catch(std::exception const &e){
		std::cout << e.what() << std::endl;
		delete formWrong;
	}

	std::cout << "\n===== TESTING =====" << std::endl;
	bureaucrat.signForm(*formPres);
	bureaucrat.executeForm(*formPres);
	bureaucrat.signForm(*formRobo);
	bureaucrat.executeForm(*formRobo);
	bureaucrat.signForm(*formShru);
	bureaucrat.executeForm(*formShru);

	delete formPres;
	delete formRobo;
	delete formShru;
	return (0);
}
