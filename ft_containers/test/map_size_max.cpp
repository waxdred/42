/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size_max.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 13:41:38 by jmilhas           #+#    #+#             */
/*   Updated: 2022/07/20 13:44:07 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"

int main(void)
{
	std::stringstream my;
	std::stringstream origine;
	
	int i;
 	std::map<int,int> map;
 	ft::map<int,int> mymap;

 	if (mymap.max_size()>1000)
 	{
 	 	for (i=0; i<1000; i++) mymap[i]=0;
 	 	my << "The map contains 1000 elements.\n";
 	}
 	else my << "The map could not hold 1000 elements.\n";

 	if (map.max_size()>1000)
 	{
 	 	for (i=0; i<1000; i++) map[i]=0;
 	 	origine << "The map contains 1000 elements.\n";
 	}
 	else origine << "The map could not hold 1000 elements.\n";
	std::string my_vector = my.str();
	std::string origine_vector = origine.str();
	std::cout << "Output cout: " << std::endl;
	std::cout << my_vector << std::endl;
	std::cout << origine_vector << std::endl;

	if (my_vector != origine_vector)
		return (1);
	return 0;
}
