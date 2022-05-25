/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_clear.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 00:15:27 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/25 20:06:14 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"

# include "header.hpp"

int main(void)
{
	std::stringstream my;
	std::stringstream origine;
	
	std::vector<int> vector;
	ft::vector<int> myvector;

  	vector.push_back (100);
  	vector.push_back (200);
  	vector.push_back (300);
  	myvector.push_back (100);
  	myvector.push_back (200);
  	myvector.push_back (300);

  	std::cout << "myvector contains:";
  	for (unsigned i=0; i < myvector.size(); i++){
  		std::cout << ' ' << myvector[i];
  		my << ' ' << myvector[i];
	}

  	std::cout << '\n';
  	for (unsigned i=0; i < vector.size(); i++){
  		std::cout << ' ' << vector[i];
  		origine << ' ' << vector[i];
	}
  	std::cout << '\n';

  	myvector.clear();
  	myvector.push_back (1101);
  	myvector.push_back (2202);
  	vector.clear();
  	vector.push_back (1101);
  	vector.push_back (2202);

  	std::cout << "myvector contains:";
  	for (unsigned i=0; i<myvector.size(); i++){
  		std::cout << ' ' << myvector[i];
		my << ' ' << myvector[i];
	}
  	std::cout << '\n';
  	
	std::cout << "vector contains:";
  	for (unsigned i=0; i < vector.size(); i++){
  		std::cout << ' ' << vector[i];
		origine << ' ' << vector[i];
	}
  	std::cout << '\n';

	std::string my_vector = my.str();
	std::string origine_vector = origine.str();
	if (my_vector != origine_vector)
		return (1);
	return 0;
}
