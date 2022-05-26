/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_capacity.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 20:47:30 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/25 20:50:03 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"

int main(void)
{
	std::stringstream my;
	std::stringstream origine;
	
	std::vector<int> vector;
	ft::vector<int> myvector;

  	// set some content in the vector:
  	for (int i=0; i<100; i++){
		myvector.push_back(i);
		vector.push_back(i);
	}
  	
  	std::cout << "size: " << (int) myvector.size() << '\n';
  	std::cout << "capacity: " << (int) myvector.capacity() << '\n';
  	std::cout << "max_size: " << (int) myvector.max_size() << '\n';
  	my << "size: " << (int) myvector.size() << '\n';
  	my << "capacity: " << (int) myvector.capacity() << '\n';
  	my << "max_size: " << (int) myvector.max_size() << '\n';

  	std::cout << "size: " << (int) vector.size() << '\n';
  	std::cout << "capacity: " << (int) vector.capacity() << '\n';
  	std::cout << "max_size: " << (int) vector.max_size() << '\n';
  	origine << "size: " << (int) vector.size() << '\n';
  	origine << "capacity: " << (int) vector.capacity() << '\n';
  	origine << "max_size: " << (int) vector.max_size() << '\n';
	std::string my_vector = my.str();
	std::string origine_vector = origine.str();
	if (my_vector != origine_vector)
		return (1);
	return 0;
}
