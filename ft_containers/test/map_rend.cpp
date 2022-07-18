/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rbegin.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 00:23:07 by jmilhas           #+#    #+#             */
/*   Updated: 2022/07/18 00:25:20 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"

int main(void)
{
	std::stringstream my;
	std::stringstream origine;
	
	std::map<char,int> map;
	ft::map<char,int> mymap;

  	map['x'] = 100;
  	map['y'] = 200;
  	map['z'] = 300;
  	mymap['x'] = 100;
  	mymap['y'] = 200;
  	mymap['z'] = 300;
  	
  	// show content:
  	std::map<char,int>::reverse_iterator rit;
  	for (rit=map.rbegin(); rit!=map.rend(); ++rit)
  	  	std::cout << rit->first << " => " << rit->second << '\n';
  	ft::map<char,int>::reverse_iterator myrit;
  	for (myrit=mymap.rbegin(); myrit!=mymap.rend(); ++myrit)
  	  	std::cout << myrit->first << " => " << myrit->second << '\n';
	std::string my_vector = my.str();
	std::string origine_vector = origine.str();
	std::cout << "Output cout: " << std::endl;
	std::cout << my_vector << std::endl;
	std::cout << origine_vector << std::endl;

	if (my_vector != origine_vector)
		return (1);
	return 0;
}
