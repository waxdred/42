/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator_traits.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 12:17:14 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/26 12:22:13 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"
#include <iterator>     // std::iterator_traits
#include <typeinfo>     // typeid


int main(void)
{
	std::stringstream my;
	std::stringstream origine;

	typedef std::iterator_traits<int*> traits;
  	if (typeid(traits::iterator_category)==typeid(std::random_access_iterator_tag))
	{
    		std::cout << "int* is a random-access iterator";
    		origine << "int* is a random-access iterator";
	}
	
	typedef ft::iterator_traits<int*> trait;
  	if (typeid(trait::iterator_category)==typeid(std::random_access_iterator_tag))
	{
    		std::cout << "int* is a random-access iterator";
    		my << "int* is a random-access iterator";
	}
	std::string my_vector = my.str();
	std::string origine_vector = origine.str();
	std::cout << "Output cout: " << std::endl;
	std::cout << my_vector << std::endl;
	std::cout << origine_vector << std::endl;

	if (my_vector != origine_vector)
		return (1);
	return 0;
}
