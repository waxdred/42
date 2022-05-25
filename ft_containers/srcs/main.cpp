/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:33:06 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/25 20:38:51 by jmilhas          ###   ########.fr       */
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

	std::vector<int> myvector;
	ft::vector<int> vector;
  	int sum (0);
  	int m_sum (0);

  	myvector.push_back (100);
  	myvector.push_back (200);
  	myvector.push_back (300);

  	vector.push_back (100);
  	vector.push_back (200);
  	vector.push_back (300);

  	while (!myvector.empty())
  	{
  		sum += myvector.back();
  		myvector.pop_back();
  	}
  	while (!vector.empty())
  	{
  		m_sum += vector.back();
  		vector.pop_back();
  	}

  	std::cout << "The elements of vector add up to " << sum << '\n';
  	origine << "The elements add up to " << sum << '\n';

  	std::cout << "The elements of myvector add up to " << m_sum << '\n';
  	my << "The elements add up to " << m_sum << '\n';
	
	std::string my_vector = my.str();
	std::string origine_vector = origine.str();
	if (my_vector != origine_vector)
		return (1);
	return 0;
	return 0;
}


