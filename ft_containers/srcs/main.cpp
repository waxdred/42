/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:33:06 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/26 15:11:40 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "vector_iterator.hpp"
#include "stack.hpp"
#include "algorithm.hpp"
#include <iostream>
#include <vector>
#include <stack>
#include <sstream>

bool mycomp (char c1, char c2)
{ return std::tolower(c1) < std::tolower(c2); }

int main(void)
{
	ft::vector<int> myvector;
	std::vector<int> vector;
	std::stringstream my;
	std::stringstream origine;


  	// set some values (from 1 to 10)
  	for (int i=1; i<=10; i++){
		myvector.push_back(i);
		vector.push_back(i);
	}  	
  	// erase the 6th element
  	myvector.erase (myvector.begin()+5);
  	vector.erase (vector.begin()+5);
  	
  	// erase the first 3 elements:
  	myvector.erase (myvector.begin(),myvector.begin()+3);
  	vector.erase (vector.begin(),vector.begin()+3);
  	
	std::cout << "My vector: "<< std::endl;
  	for (unsigned i=0; i<myvector.size(); ++i){
  	  	my << ' ' << myvector[i];
		std::cout << ' ' << myvector[i];
	}
	std::cout << std::endl;
  	
	std::cout << "vector: "<< std::endl;
	for (unsigned i=0; i < vector.size(); ++i){
  	  	origine << ' ' << vector[i];
		std::cout << ' ' << vector[i];
	}
	std::cout << std::endl;

	std::string my_vector = my.str();
	std::string origine_vector = origine.str();
	std::cout << my_vector << '\n' << origine_vector << std::endl;
	if (my_vector != origine_vector)
		return (1);
	return 0;
}


