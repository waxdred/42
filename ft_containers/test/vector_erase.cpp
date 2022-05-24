/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_erase.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 22:13:31 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/24 23:15:04 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

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
  	
  	for (unsigned i=0; i<myvector.size(); ++i)
  	  my << ' ' << myvector[i];
  	
	for (unsigned i=0; i < vector.size(); ++i)
  	  origine << ' ' << vector[i];

	std::string my_vector = my.str();
	std::string origine_vector = origine.str();
	std::cout << my_vector << '\n' << origine_vector << std::endl;
	if (my_vector != origine_vector)
		return (1);
	return 0;
}
