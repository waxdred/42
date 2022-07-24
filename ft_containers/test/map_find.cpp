/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_find.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 13:23:57 by jmilhas           #+#    #+#             */
/*   Updated: 2022/07/25 01:03:06 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"

# include "header.hpp"

int main(void)
{
	std::stringstream my;
	std::stringstream origine;
	
	std::map<char,int> map;
  	std::map<char,int>::iterator it;
	ft::map<char,int> mymap;
  	ft::map<char,int>::iterator mit;

  	map['a']=50;
  	map['b']=100;
  	map['c']=150;
  	map['d']=200;
  	mymap['a']=50;
  	mymap['b']=100;
  	mymap['c']=150;
  	mymap['d']=200;

	mit = mymap.find('d');
 	if (mit != mymap.end())
    		mymap.erase (mit);

	it = map.find('d');
 	if (it != map.end())
    		map.erase (it);

	my << "a => " << mymap.find('a')->second << '\n';
  	my << "c => " << mymap.find('c')->second << '\n';
	std::cout << "d => " << mymap.find('d')->second << '\n';
	origine << "a => " << map.find('a')->second << '\n';
  	origine << "c => " << map.find('c')->second << '\n';
	std::cout << "d => " << map.find('d')->second << '\n';

	std::string my_vector = my.str();
	std::string origine_vector = origine.str();
	std::cout << "Output cout: " << std::endl;
	std::cout << my_vector << std::endl;
	std::cout << origine_vector << std::endl;

	if (my_vector != origine_vector)
		return (1);
	return 0;
}
