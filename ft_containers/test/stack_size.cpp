/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_size.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:02:49 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/26 14:05:22 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"

int main(void)
{
	std::stringstream my;
	std::stringstream origine;
	
	std::stack<int> ints;
	ft::stack<int> myints;
  	std::cout << "0. size: " << myints.size() << '\n';
  	std::cout << "0. size: " << ints.size() << '\n';
  	my << "0. size: " << myints.size() << '\n';
  	origine << "0. size: " << ints.size() << '\n';

 	for (int i=0; i<5; i++){
		myints.push(i);
		ints.push(i);
	}
  	
	std::cout << "1. size: " << myints.size() << '\n';
	std::cout << "1. size: " << ints.size() << '\n';
	my << "1. size: " << myints.size() << '\n';
	origine << "1. size: " << ints.size() << '\n';

  	myints.pop();
  	ints.pop();
  	std::cout << "2. size: " << myints.size() << '\n';
  	std::cout << "2. size: " << ints.size() << '\n';
  	my << "2. size: " << myints.size() << '\n';
  	origine << "2. size: " << ints.size() << '\n';

	std::string my_vector = my.str();
	std::string origine_vector = origine.str();
	std::cout << "Output cout: " << std::endl;
	std::cout << my_vector << std::endl;
	std::cout << origine_vector << std::endl;

	if (my_vector != origine_vector)
		return (1);
	return 0;
}
