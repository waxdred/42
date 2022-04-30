/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_cast.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 08:24:41 by jmilhas           #+#    #+#             */
/*   Updated: 2022/04/29 08:44:37 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <typeinfo>
#include <exception>

class Parent{
	public: virtual ~Parent(void){};
};
class Child1: public Parent{};
class Child2: public Parent{};

int main(void)
{
	Child1 a;
	Parent *b = &a;

	Child1 *c = dynamic_cast<Child1 *>(b);
	if (!c)
		std::cout << "Conversion is not ok" << std::endl;
	else{
		std::cout << "Conversion ok" << std::endl;
	}
	Parent *ea = &a;
	try{
		Child2 &b = dynamic_cast<Child2 &>(*ea);
		std::cout << "Conversion is ok" << std::endl;
	}catch(std::bad_cast &bc){
		std::cout << "Conversion is not ok: " << bc.what() << std::endl;
		return (0);
	}
	return 0;
}
