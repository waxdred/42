/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 17:48:41 by jmilhas           #+#    #+#             */
/*   Updated: 2022/04/30 18:37:09 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class.hpp"
#include <exception>

int main(void)
{
	Perso p1("todo", 43, true);

	std::cout << p1;
	try{
		p1 + p1;

	}catch(std::exception const &e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << p1;
	return 0;
}
