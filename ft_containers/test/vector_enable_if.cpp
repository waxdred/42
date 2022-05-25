/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_enable_if.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 09:23:00 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/25 09:38:49 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"

// 1. the return type (bool) is only valid if T is an integral type:
template <class T>
typename std::enable_if<std::is_integral<T>::value,bool>::type
  is_odd (T i) {return bool(i%2);}

template <class T>
typename std::enable_if<std::is_integral<T>::value,bool>::type
  is_even (T i) {return !bool(i%2);}
int main(void)
{
	std::stringstream my;
	std::stringstream origine;
	
	short int i = 1;    // code does not compile if type of i is not integral

  	std::cout << std::boolalpha;
  	std::cout << "i is odd: " << is_odd(i) << std::endl;
	std::cout << "i is even: " << is_even(i) << std::endl;
  	my << "i is odd: " << is_odd(i) << std::endl;
	my << "i is even: " << is_even(i) << std::endl;
  	origine << "i is odd: " << "1" << std::endl;
	origine << "i is even: " << "0" << std::endl;

	std::string my_vector = my.str();
	std::string origine_vector = origine.str();
	std::cout << "Output cout: " << std::endl;
	std::cout << my_vector << std::endl;
	std::cout << origine_vector << std::endl;
	if (my_vector != origine_vector)
		return (1);
	return 0;
}
