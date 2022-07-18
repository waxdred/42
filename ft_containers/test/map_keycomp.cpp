/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_keycomp.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 07:34:41 by jmilhas           #+#    #+#             */
/*   Updated: 2022/07/17 23:32:11 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"

int main(void)
{
	std::stringstream my;
	std::stringstream origine;
	
	std::map<char,int> map;
  	std::map<char,int>::key_compare comp = map.key_comp();
  	
  	map['a']=100;
  	map['b']=200;
  	map['c']=300;
	ft::map<char,int> mymap;
  	ft::map<char,int>::key_compare mycomp = mymap.key_comp();
  	
  	mymap['a']=100;
  	mymap['b']=200;
  	mymap['c']=300;
  	
  	std::cout << "mymap contains:\n";
  	
  	char highest = mymap.rbegin()->first;     // key value of last element
  	char highests = map.rbegin()->first;     // key value of last element
  	
  	ft::map<char,int>::iterator it = mymap.begin();
  	std::map<char,int>::iterator its = map.begin();
  	do {
  	  my << it->first << " => " << it->second << '\n';
	  it++;
  	} while ( mycomp(it->first, highest) );
  	
  	std::cout << "mymap contains:\n";
  	do {
  	  origine << its->first << " => " << its->second << '\n';
	  ++its;
  	} while ( comp(its->first, highests) );
  	std::cout << '\n';
	std::string my_vector = my.str();
	std::string origine_vector = origine.str();
	std::cout << "Output cout: " << std::endl;
	std::cout << my_vector << std::endl;
	std::cout << origine_vector << std::endl;

	if (my_vector != origine_vector)
		return (1);
	return 0;
}

