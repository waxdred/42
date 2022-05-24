/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_assign.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 23:17:10 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/24 23:25:06 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

int main(void)
{
	std::stringstream my;
	std::stringstream origine;
	ft::vector<int> first;
  	ft::vector<int> second;
  	ft::vector<int> third;
	ft::vector<int> it;

	std::vector<int> v_first;
  	std::vector<int> v_second;
  	std::vector<int> v_third;
	std::vector<int> v_it;


	it.push_back(0);
	it.push_back(1);
	it.push_back(2);
	it.push_back(3);
	v_it.push_back(0);
	v_it.push_back(1);
	v_it.push_back(2);
	v_it.push_back(3);
  	
  	
	second.assign(it.begin() + 1, it.end());
	v_second.assign(v_it.begin(), v_it.end());
  	first.assign (7,100);             // 7 ints with a value of 100
  	v_first.assign (7,100);             // 7 ints with a value of 100
  	
  	int myints[] = {1776,7,4};
  	third.assign (myints,myints+3);   // assigning from array.
  	v_third.assign (myints,myints+3);   // assigning from array.
  	
  	std::cout << "Size of first: " << int (first.size()) << '\n';
  	my << "Size of first: " << int (first.size()) << '\n';
  	origine << "Size of first: " << int (first.size()) << '\n';

  	std::cout << "Size of second: " << int (second.size()) << '\n';
  	my << "Size of second: " << int (second.size()) << '\n';
  	origine << "Size of second: " << int (second.size()) << '\n';

  	std::cout << "Size of third: " << int (third.size()) << '\n';
  	my << "Size of third: " << int (third.size()) << '\n';
  	origine << "Size of third: " << int (third.size()) << '\n';
	std::string my_vector = my.str();
	std::string origine_vector = origine.str();
	if (my_vector != origine_vector)
		return (1);
	return 0;
}
