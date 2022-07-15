/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_begin.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:14:39 by jmilhas           #+#    #+#             */
/*   Updated: 2022/07/14 23:35:33 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"


int main(void)
{
	std::stringstream my;
	std::stringstream origine;

	std::map<char,int> map;
	ft::map<char,int> mymap;

  	map['b'] = 100;
	map['a'] = 200;
  	map['c'] = 300;

  	mymap['b'] = 100;
	mymap['a'] = 200;
  	mymap['c'] = 300;
  	for (std::map<char,int>::iterator it=map.begin(); it!=map.end(); ++it)
    		origine << it->first << " => " << it->second << '\n';
  	for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    		my << it->first << " => " << it->second << '\n';
	
	std::string my_vector = my.str();
	std::string origine_vector = origine.str();
	std::cout << "Output cout: " << std::endl;
	std::cout << my_vector << std::endl;
	std::cout << origine_vector << std::endl;

	if (my_vector != origine_vector)
		return (1);
	return 0;
}
