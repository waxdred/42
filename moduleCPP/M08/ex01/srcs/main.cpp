/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 09:32:51 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/01 15:16:45 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <exception>

int main(void)
{
	Span sp = Span(5);
	Span vp(10);
	std::vector<int> vec{1, 2, 2, 3, 4, 5, 8};
	Span vect(10);
	
	std::cout << "===Test main 42 ===" << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	try{
		std::cout << "\n=== Add vector in addNumber ===" << std::endl;
	        vect.addNumber(vec);
		std::cout << "test if span full size" << std::endl;
	        vect.addNumber(vec);
	}catch(std::exception &e){
		std::cout << "Exception: " << e.what() << std::endl;
	}
	try{
		std::cout << "\n=== Add int in addNumber ===" << std::endl;
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "test if span full size" << std::endl;
		sp.addNumber(11);
	}catch(std::exception &e){
		std::cout << "Exception: " << e.what() << std::endl;
	}
	try{
		std::cout << "\n=== Add list in addNumber ===" << std::endl;
		vp.addNumber({1, 42, 45, 56, 48, 86, 56});
		std::cout << "test if span full size" << std::endl;
		vp.addNumber({1, 42, 45, 56, 48, 86, 56});
	}catch(std::exception &e){
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return 0;
}
