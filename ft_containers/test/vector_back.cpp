/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_back.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:07:10 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/25 19:10:04 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"

int main(void)
{
	std::stringstream my;
	std::stringstream origine;
	
	std::vector<int> myvector;
	std::vector<int> vector;
 
  	myvector.push_back(10);
  	vector.push_back(10);

  	while (myvector.back() != 0)
  	{
  		myvector.push_back ( myvector.back() -1 );
  	}
  	while (vector.back() != 0)
  	{
  		vector.push_back ( vector.back() -1 );
  	}

  	std::cout << "vector contains:";
  	for (unsigned i=0; i<myvector.size() ; i++)
	{
  		std::cout << ' ' << myvector[i];
  		origine << ' ' << myvector[i];
	}
  	std::cout << '\n';

  	std::cout << "myvector contains:";
  	for (unsigned i=0; i< vector.size() ; i++)
	{
  		std::cout << ' ' << vector[i];
  		my << ' ' << vector[i];
	}
  	std::cout << '\n';
	std::string my_vector = my.str();
	std::string origine_vector = origine.str();
	if (my_vector != origine_vector)
		return (1);
	return 0;
}
