/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 13:45:54 by jmilhas           #+#    #+#             */
/*   Updated: 2022/07/20 13:47:16 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"

int main(void)
{
	std::stringstream my;
	std::stringstream origine;
	

	std::map<char,int> map;
	ft::map<char,int> mymap;
 	mymap['a']=101;
 	mymap['b']=202;
 	mymap['c']=302;
 	map['a']=101;
 	map['b']=202;
 	map['c']=302;

 	my << "mymap.size() is " << mymap.size() << '\n';
 	origine << "mymap.size() is " << map.size() << '\n';
	std::string my_vector = my.str();
	std::string origine_vector = origine.str();
	std::cout << "Output cout: " << std::endl;
	std::cout << my_vector << std::endl;
	std::cout << origine_vector << std::endl;

	if (my_vector != origine_vector)
		return (1);
	return 0;
}
