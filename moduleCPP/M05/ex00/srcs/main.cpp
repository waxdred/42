/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:20:14 by jmilhas           #+#    #+#             */
/*   Updated: 2022/04/22 14:29:16 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iterator>

int main(void)
{
	std::string	p1 = "Jean";
	std::string	p2 = "Robert";
	std::string	p3 = "Chirstine";
	std::string	p4 = "Claire";
	Bureaucrat b1;
	Bureaucrat b2(p1);

	std::cout << b1;
	std::cout << b2;
	try{
		std::cout << b1;
		std::cout << "decremente" << std::endl;
		b1.decrementeGrade();
		std::cout << b1;
	}catch(std::exception const &e){
		std::cerr << e.what() << std::endl;
	}
	try{
		std::cout << b2;
		std::cout << "incremente" << std::endl;
		b2.incrementeGrade();
		std::cout << b2;
	}catch(std::exception const &e){
		std::cerr << e.what() << std::endl;
	}

	try {
		std::cout << "Try creation Bureaucrat avec une grade de -1" << std::endl;
		Bureaucrat b3(p2, -1);
		std::cout << b3;
	}catch(std::exception const &e){
		std::cerr << p2 << " " << e.what() << std::endl;
	}
	try {
		std::cout << "Try creation Bureaucrat avec une grade de 151" << std::endl;
		Bureaucrat b4(151);
		std::cout << b4;
	}catch(std::exception const &e){
		std::cerr << "Anonymous" << " " << e.what() << std::endl;
	}
	try{
		std::cout << "Try creation Bureaucrat avec grade 150 et update" << std::endl;
		Bureaucrat b5(150);
		std::cout << b5;
		b5.decrementeGrade();
		std::cout << b5;
	}catch(std::exception const &e){
		std::cerr << "Anonymous " << e.what() << std::endl;
	}
	try{
		std::cout << "Try creation Bureaucrat avec grade 150 et update" << std::endl;
		Bureaucrat b5(0);
		std::cout << b5;
		b5.incrementeGrade();
		std::cout << b5;
	}catch(std::exception const &e){
		std::cerr << "Anonymous " << e.what() << std::endl;
	}
	return 0;
}
