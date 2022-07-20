/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_operator1.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 13:19:13 by jmilhas           #+#    #+#             */
/*   Updated: 2022/07/20 13:24:41 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"

int main(void)
{
	std::stringstream my;
	std::stringstream origine;
	
	std::map<char,std::string> map;
	ft::map<char,std::string> mymap;

 	mymap['a']="an element";
 	mymap['b']="another element";
 	mymap['c']=mymap['b'];
 	map['a']="an element";
 	map['b']="another element";
 	map['c']=mymap['b'];

 	my << "mymap['a'] is " << mymap['a'] << '\n';
 	my << "mymap['b'] is " << mymap['b'] << '\n';
 	my << "mymap['c'] is " << mymap['c'] << '\n';
 	my << "mymap['d'] is " << mymap['d'] << '\n';

 	origine << "mymap['a'] is " << map['a'] << '\n';
 	origine << "mymap['b'] is " << map['b'] << '\n';
 	origine << "mymap['c'] is " << map['c'] << '\n';
 	origine << "mymap['d'] is " << map['d'] << '\n';

 	std::cout << "mymap now contains " << mymap.size() << " elements.\n";
 	std::cout << "mymap now contains " << map.size() << " elements.\n";
	std::string my_vector = my.str();
	std::string origine_vector = origine.str();
	std::cout << "Output cout: " << std::endl;
	std::cout << my_vector << std::endl;
	std::cout << origine_vector << std::endl;

	if (my_vector != origine_vector)
		return (1);
	return 0;
}
