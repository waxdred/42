/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_allocator.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:21:02 by jmilhas           #+#    #+#             */
/*   Updated: 2022/07/06 15:25:37 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"

int main(void)
{
	std::stringstream my;
	std::stringstream origine;
	
	std::vector<int> myvector;
	ft::vector<int> vector;
  	int * p;
  	unsigned int i;
  	int * c;
  	
  	// allocate an array with space for 5 elements using vector's allocator:
  	p = myvector.get_allocator().allocate(5);
  	c = myvector.get_allocator().allocate(5);
	
  	
  	// construct values in-place on the array:
  	for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);
  	for (i=0; i<5; i++) vector.get_allocator().construct(&p[i],i);
  	
  	std::cout << "The allocated array contains:";
  	for (i=0; i<5; i++) origine << ' ' << p[i];
  	for (i=0; i<5; i++) my << ' ' << c[i];
  	std::cout << '\n';
  	
  	// destroy and deallocate:
  	for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
  	for (i=0; i<5; i++) vector.get_allocator().destroy(&c[i]);
  	myvector.get_allocator().deallocate(p,5);
  	vector.get_allocator().deallocate(p,5);
	
	std::string my_vector = my.str();
	std::string origine_vector = origine.str();
	std::cout << "Output cout: " << std::endl;
	std::cout << my_vector << std::endl;
	std::cout << origine_vector << std::endl;

	if (my_vector != origine_vector)
		return (1);
	return 0;
}
