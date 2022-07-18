/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_value_comp.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 23:44:59 by jmilhas           #+#    #+#             */
/*   Updated: 2022/07/18 00:19:34 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"

int main(void)
{
	std::stringstream my;
	std::stringstream origine;
	
	std::map<char,int> map;
	ft::map<char,int> mymap;

  	map['x']=1001;
  	map['y']=2002;
  	map['z']=3003;
  	mymap['x']=1001;
  	mymap['y']=2002;
  	mymap['z']=3003;
  	
  	std::cout << "map contains:\n";
  	
  	std::pair<char,int> highest('z', 3003);          // last element
  	ft::pair<char,int> myhighest('z', 3003);          // last element
  	
  	std::map<char,int>::iterator it = map.begin();
  	ft::map<char,int>::iterator myit = mymap.begin();
  	do {
  	  	std::cout << it->first << " => " << it->second << '\n';
		it++;
  	} while ( map.value_comp()(*it, highest) );
	ft::map<char, int>::value_compare t = mymap.value_comp();	
  	do {
  	  	std::cout << myit->first << " => " << myit->second << '\n';
		myit++;
  	} while ( mymap.value_comp()(myit.getNode()->content, highest) );
	std::string my_vector = my.str();
	std::string origine_vector = origine.str();
	std::cout << "Output cout: " << std::endl;
	std::cout << my_vector << std::endl;
	std::cout << origine_vector << std::endl;

	if (my_vector != origine_vector)
		return (1);
	return 0;
}
