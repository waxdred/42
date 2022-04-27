/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:20:14 by jmilhas           #+#    #+#             */
/*   Updated: 2022/04/27 11:52:51 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	std::string	p1 = "Jean";
	std::string	p2 = "Robert";
	std::string	p3 = "Chirstine";
	std::string	p4 = "Claire";
	Bureaucrat b1;
	Bureaucrat b2(p1);

	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	std::cout << "\nNew try:" << std::endl;
	try{
		std::cout << b1 << std::endl;
		std::cout << "decremente" << std::endl;
		b1.decrementGrade();
		std::cout << b1 << std::endl;
	}catch(std::exception const &e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\nNew try:" << std::endl;
	try{
		std::cout << b2 << std::endl;
		std::cout << "incremente" << std::endl;
		b2.incrementGrade();
		std::cout << b2 << std::endl;
	}catch(std::exception const &e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\nNew try:" << std::endl;
	try {
		std::cout << "Try creation Bureaucrat avec une grade de -1" << std::endl;
		Bureaucrat b3(p2, -1);
		std::cout << b3 << std::endl;
	}catch(std::exception const &e){
		std::cerr << p2 << " " << e.what() << std::endl;
	}
	std::cout << "\nNew try:" << std::endl;
	try {
		std::cout << "Try creation Bureaucrat avec une grade de 151" << std::endl;
		Bureaucrat b4(151);
		std::cout << b4 << std::endl;
	}catch(std::exception const &e){
		std::cerr << "Anonymous" << " " << e.what() << std::endl;
	}
	std::cout << "\nNew try:" << std::endl;
	try{
		std::cout << "Try creation Bureaucrat avec grade 150 et update" << std::endl;
		Bureaucrat b5(150);
		std::cout << b5 << std::endl;
		b5.decrementGrade();
		std::cout << b5 << std::endl;
	}catch(std::exception const &e){
		std::cerr << "Anonymous " << e.what() << std::endl;
	}
	std::cout << "\nNew try:" << std::endl;
	try{
		std::cout << "Try creation Bureaucrat avec grade 150 et update" << std::endl;
		Bureaucrat b5(0);
		std::cout << b5 << std::endl;
		b5.incrementGrade();
		std::cout << b5 << std::endl;
	}catch(std::exception const &e){
		std::cerr << "Anonymous " << e.what() << std::endl;
	}
	return 0;
}
