/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_clear.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 23:22:45 by jmilhas           #+#    #+#             */
/*   Updated: 2022/07/15 23:27:14 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"

int main(void)
{
	std::stringstream my;
	std::stringstream origine;

	std::map<char,int> map;
	ft::map<char,int> mymap;

  	map['x']=100;
  	map['y']=200;
  	map['z']=300;
  	mymap['x']=100;
  	mymap['y']=200;
  	mymap['z']=300;
  	
  	std::cout << "map contains:\n";
  	for (std::map<char,int>::iterator it=map.begin(); it!=map.end(); ++it)
  		origine << it->first << " => " << it->second << '\n';
  	for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
  		my << it->first << " => " << it->second << '\n';
  	
  	map.clear();
  	map['a']=1101;
  	map['b']=2202;
  	mymap.clear();
  	mymap['a']=1101;
  	mymap['b']=2202;
  	
  	std::cout << "map contains:\n";
  	for (std::map<char,int>::iterator it=map.begin(); it!=map.end(); ++it)
  		origine << it->first << " => " << it->second << '\n';
  	std::cout << "map contains:\n";
  	for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
  		my << it->first << " => " << it->second << '\n';
	
	std::string my_vector = my.str();
	std::string origine_vector = origine.str();
	if (my_vector != origine_vector)
		return (1);
	return 0;
}
