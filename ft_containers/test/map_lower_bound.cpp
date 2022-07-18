/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_lower_bound.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 00:42:45 by jmilhas           #+#    #+#             */
/*   Updated: 2022/07/18 11:49:24 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"

# include "header.hpp"
#include <iostream>

int main(void)
{
	std::stringstream my;
	std::stringstream origine;
	
	ft::map<char,int> mymap;
  	ft::map<char,int>::iterator myitlow ,myitup;
	std::map<char,int> map;
  	std::map<char,int>::iterator itlow ,itup;
	mymap['a']=20;
  	mymap['b']=40;
  	mymap['c']=60;
  	mymap['d']=80;
  	mymap['e']=100;
  	
	map['a']=20;
  	map['b']=40;
  	map['c']=60;
  	map['d']=80;
  	map['e']=100;
  	myitlow=mymap.lower_bound ('b');  // itlow points to b
  	itlow=map.lower_bound ('b');  // itlow points to b
	itup=map.upper_bound ('d');
	myitup=mymap.upper_bound ('d');
  	
  	mymap.erase(myitlow);        // erases [itlow,itup)
  	map.erase(itlow);        // erases [itlow,itup)
  	
  	// print content:
  	for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
  		my << it->first << " => " << it->second << '\n';
  	for (std::map<char,int>::iterator its=map.begin(); its!=map.end(); ++its)
  		origine << its->first << " => " << its->second << '\n';
	std::string my_vector = my.str();
	std::string origine_vector = origine.str();
	std::cout << "Output cout: " << std::endl;
	std::cout << my_vector << std::endl;
	std::cout << origine_vector << std::endl;

	if (my.str() != origine.str())
		return (1);
	return 0;
}
