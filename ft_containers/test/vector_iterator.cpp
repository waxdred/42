/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 22:50:14 by jmilhas           #+#    #+#             */
/*   Updated: 2022/06/28 02:23:52 by jmilhas          ###   ########.fr       */
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

	


	ft::vector<int> myvector;
	myvector.push_back(10);
	myvector.push_back(20);
	myvector.push_back(30);
	myvector.push_back(40);
	myvector.push_back(50);
	// const test
  	std::cout << "myvector contains:";
	*(myvector.begin()) = 100;

  	for (auto it = myvector.begin(); it != myvector.end(); ++it)
  	  	my << ' ' << *it;
  	std::cout << '\n';

	std::vector<int> vector = {10,20,30,40,50};
	*(vector.begin()) = 100;

  	std::cout << "myvector contains:";

  	for (auto it = vector.begin(); it != vector.end(); ++it)
  	  	origine << ' ' << *it;
  	std::cout << '\n';
	//end

	std::cout <<  "Iterator empty\n" << v << std::endl;
	for (int i = 1; i < 11; i++)
	{
		val.append(std::to_string(i));
		v.push_back(val);
		vt.push_back(val);
	}
	std::cout << "My vector test" << std::endl;
	for (ft::iterator i = v.begin(); i != v.end(); i++){
		std::cout << *i << ' ';
		my << *i << ' ';
	}
	std::cout << "\nvector test" << std::endl;
	for (std::vector<std::string>::iterator i = vt.begin(); i != vt.end(); i++){
		std::cerr << *i << ' ';
		origine << *i << ' ';
	}
	std::cout << "My vector test" << std::endl;
	for (ft::iterator i = v.begin() + 2; i != v.end(); i++){
		std::cout << *i << ' ';
		my << *i << ' ';
	}
	std::cout << "\nvector test" << std::endl;
	for (std::vector<std::string>::iterator i = vt.begin() + 2; i != vt.end(); i++){
		std::cerr << *i << ' ';
		origine << *i << ' ';
	}
	std::string my_vector = my.str();
	std::string origine_vector = origine.str();
	if (my_vector != origine_vector)
		return (1);
	return 0;
}
