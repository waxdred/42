/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Info.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 22:40:20 by jmilhas           #+#    #+#             */
/*   Updated: 2022/04/29 23:10:03 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Info.hpp"

/* @Brief gen pointer aleatoire*/
/*		   @class A */
/*		   @class B */
/*		   @class C */
/* @Return  Return(*randclass)*/
Base	*generate(void){
	int val;

	srand (time(NULL));
	val = rand() % 3;
	switch (val) {
		case 0:
			std::cout << "Gen: Class A" << std::endl;
			return (new A());
		case 1:
			std::cout << "Gen: Class B" << std::endl;
			return (new B());
		case 2:
			std::cout << "Gen: Class C" << std::endl;
			return (new C());
	}
	std::cerr << "Error! class not generates" << std::endl;
	return (NULL);
}

void	identify(Base* p){
	if (dynamic_cast<A*>(p))
		std::cout << "Class *A found it" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "Class *B found it" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "Class *C found it" << std::endl;
}

void	identify(Base& p){
	Base c;

	try{
		c = dynamic_cast<A&>(p);
		std::cout << "Class &A found it" << std::endl;
		return;
	}catch (std::bad_cast &bc){}
	try{
		c = dynamic_cast<B&>(p);
		std::cout << "Class &B found it" << std::endl;
		return;
	}catch (std::bad_cast &bc){}
	try{
		c = dynamic_cast<C&>(p);
		std::cout << "Class &C found it" << std::endl;
		return;
	}catch (std::bad_cast &bc){}
}
