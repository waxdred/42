/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 22:50:14 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/24 23:15:29 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

int main(void)
{
	ft::vector<std::string> v;
	std::vector<std::string> vt;
	std::string val =  "salut: ";
	std::stringstream my;
	std::stringstream origine;

	std::cout <<  "Iterator empty\n" << v << std::endl;
	for (int i = 1; i < 11; i++)
	{
		val.append(std::to_string(i));
		v.push_back(val);
		vt.push_back(val);
	}
	std::cout << "My vector test" << std::endl;
	for (ft::vector_iterator i = v.begin(); i != v.end(); i++){
		std::cout << *i << ' ';
		my << *i << ' ';
	}
	std::cout << "\nvector test" << std::endl;
	for (std::vector<std::string>::iterator i = vt.begin(); i != vt.end(); i++){
		std::cerr << *i << ' ';
		origine << *i << ' ';
	}
	std::string my_vector = my.str();
	std::string origine_vector = origine.str();
	if (my_vector != origine_vector)
		return (1);
	return 0;
}
