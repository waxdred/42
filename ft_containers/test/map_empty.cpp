/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_empty.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:38:53 by jmilhas           #+#    #+#             */
/*   Updated: 2022/07/16 23:03:49 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"
#include <utility>

int main(void)
{
	std::stringstream my;
	std::stringstream origine;
	std::map<char,int> map;
	ft::map<char,int> mymap;

  	map['a']=10;
  	map['b']=20;
  	map['c']=30;

  	mymap['a']=10;
  	mymap['b']=20;
  	mymap['c']=30;
  	while (!mymap.empty())
  	{
  	  	my << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
  	  	mymap.erase(mymap.begin());
  	}
  	while (!map.empty())
  	{
  	  	origine << map.begin()->first << " => " << map.begin()->second << '\n';
  	  	map.erase(map.begin());
  	}
	std::string my_vector = my.str();
	std::string origine_vector = origine.str();
	std::cout << "Output cout: " << std::endl;
	std::cout << my_vector << std::endl;
	std::cout << "Output cout: " << std::endl;
	std::cout << origine_vector << std::endl;

	if (my_vector != origine_vector)
		return (1);
	return 0;
}
