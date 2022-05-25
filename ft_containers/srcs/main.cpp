/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:33:06 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/25 09:19:15 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "vector_iterator.hpp"
#include "algorithm.hpp"
#include <iostream>
#include <vector>
#include <sstream>
bool mycomp (char c1, char c2)
{ return std::tolower(c1) < std::tolower(c2); }

int main(void)
{
	std::stringstream my;
	std::stringstream origine;
	
	char foo[]="Apple";
  	char bar[]="apartment";

  	std::cout << std::boolalpha;

  	std::cout << "Comparing foo and bar lexicographically (foo<bar):\n";

  	std::cout << "Using default comparison (operator<): ";
  	std::cout << std::lexicographical_compare(foo,foo+5,bar,bar+9);
  	std::cout << ft::lexicographical_compare(foo,foo+5,bar,bar+9);
  	my << ft::lexicographical_compare(foo,foo+5,bar,bar+9);
  	origine << std::lexicographical_compare(foo,foo+5,bar,bar+9);
  	std::cout << '\n';

  	std::cout << "Using mycomp as comparison object: ";
  	std::cout << std::lexicographical_compare(foo,foo+5,bar,bar+9,mycomp);
  	std::cout << ft::lexicographical_compare(foo,foo+5,bar,bar+9,mycomp);
  	my << ft::lexicographical_compare(foo,foo+5,bar,bar+9,mycomp);
  	origine << std::lexicographical_compare(foo,foo+5,bar,bar+9,mycomp);
  	std::cout << '\n';
	std::string my_vector = my.str();
	std::string origine_vector = origine.str();
	std::cout << "my: " << my_vector << std::endl;
	std::cout << "origine: " << origine_vector << std::endl;
	if (my_vector != origine_vector)
		return (1);
	return 0;
}

