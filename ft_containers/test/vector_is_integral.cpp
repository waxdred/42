/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_is_integral.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 09:39:43 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/25 09:42:01 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"

int main(void)
{
	std::stringstream my;
	std::stringstream origine;
	
	std::cout << std::boolalpha;
  	std::cout << "is_integral:" << std::endl;
  	std::cout << "char: " << ft::is_integral<char>::value << std::endl;
  	std::cout << "int: " << ft::is_integral<int>::value << std::endl;
  	std::cout << "float: " << ft::is_integral<float>::value << std::endl;

	my << std::boolalpha;
  	my << "is_integral:" << std::endl;
  	my << "char: " << ft::is_integral<char>::value << std::endl;
  	my << "int: " << ft::is_integral<int>::value << std::endl;
  	my << "float: " << ft::is_integral<float>::value << std::endl;

	origine << std::boolalpha;
  	origine << "is_integral:" << std::endl;
  	origine << "char: " << ft::is_integral<char>::value << std::endl;
  	origine << "int: " << ft::is_integral<int>::value << std::endl;
  	origine << "float: " << ft::is_integral<float>::value << std::endl;

	std::string my_vector = my.str();
	std::string origine_vector = origine.str();
	std::cout << "Output cout: " << std::endl;
	std::cout << my_vector << std::endl;
	std::cout << origine_vector << std::endl;

	if (my_vector != origine_vector)
		return (1);
	return 0;
}
