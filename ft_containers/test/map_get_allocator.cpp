/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get_allocator.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 08:03:01 by jmilhas           #+#    #+#             */
/*   Updated: 2022/07/17 08:07:47 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"

int main(void)
{
	std::stringstream my;
	std::stringstream origine;
	
	int psize;
  	ft::map<char,int> mymap;
  	ft::pair<const char,int>* py;
  	
	int size;
  	std::map<char,int> map;
  	std::pair<const char,int>* p;
  	
  	// allocate an array of 5 elements using mymap's allocator:
  	p=map.get_allocator().allocate(5);
  	py=mymap.get_allocator().allocate(5);
  	
  	// assign some values to array
  	psize = sizeof(ft::map<char,int>::value_type)*5;
  	size = sizeof(std::map<char,int>::value_type)*5;
  	
  	my << "The allocated array has a size of " << psize << " bytes.\n";
  	origine << "The allocated array has a size of " << size << " bytes.\n";
  	
  	mymap.get_allocator().deallocate(py,5);
  	map.get_allocator().deallocate(p,5);

	std::string my_vector = my.str();
	std::string origine_vector = origine.str();
	std::cout << "Output cout: " << std::endl;
	std::cout << my_vector << std::endl;
	std::cout << origine_vector << std::endl;

	if (my_vector != origine_vector)
		return (1);
	return 0;
}
