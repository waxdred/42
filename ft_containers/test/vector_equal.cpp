/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_equal.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 08:19:35 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/25 09:07:25 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"

bool mypredicate (int i, int j) {
  return (i==j);
}

int main(void)
{
	std::stringstream my;
	std::stringstream origine;

	int myints[] = {20,40,60,80,100};               //   myints: 20 40 60 80 100
  	std::vector<int>vector (myints,myints+5);     // myvector: 20 40 60 80 100
  	ft::vector<int>myvector (myints,myints+5);     // myvector: 20 40 60 80 100

  	// using default comparison:
  	if ( ft::equal (myvector.begin(), myvector.end(), myints) ){
  		std::cout << "The contents of both sequences are equal.\n";
  		my << "The contents of both sequences are equal.\n";
	}
  	else{
  	  	std::cout << "The contents of both sequences differ.\n";
  	  	my << "The contents of both sequences differ.\n";
	}
  	if ( std::equal (vector.begin(), vector.end(), myints) ){
  		std::cout << "The contents of both sequences are equal.\n";
  		origine << "The contents of both sequences are equal.\n";
	}
  	else{
  	  	std::cout << "The contents of both sequences differ.\n";
  	  	origine << "The contents of both sequences differ.\n";
	}
  	
  	myvector[3]=81;                                 // myvector: 20 40 60 81 100
  	vector[3]=81;                                 // myvector: 20 40 60 81 100
  	
  	// using predicate comparison:
  	if ( ft::equal (myvector.begin(), myvector.end(), myints) ){
  		std::cout << "The contents of both sequences are equal.\n";
  		my << "The contents of both sequences are equal.\n";
	}
  	else{
  	  	std::cout << "The contents of both sequences differ.\n";
  	  	my << "The contents of both sequences differ.\n";
	}
  	if ( std::equal (vector.begin(), vector.end(), myints) ){
  		std::cout << "The contents of both sequences are equal.\n";
  		origine << "The contents of both sequences are equal.\n";
	}
  	else{
  	  	std::cout << "The contents of both sequences differ.\n";
  	  	origine << "The contents of both sequences differ.\n";
	}

	std::string my_vector = my.str();
	std::string origine_vector = origine.str();
	if (my_vector != origine_vector)
		return (1);
	return 0;
}
