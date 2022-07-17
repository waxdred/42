/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_count.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 06:51:02 by jmilhas           #+#    #+#             */
/*   Updated: 2022/07/17 07:10:08 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"

int main(void)
{
	std::stringstream my;
	std::stringstream origine;
	
	std::map<char,int> map;
	ft::map<char,int> mymap;
  	char c;
  	char d;
  	
  	map ['a']=101;
  	map ['c']=202;
  	map ['f']=303;
  	
  	for (c='a'; c<'h'; c++)
  	{
  	  	origine << c;
  	  	if (map.count(c)>0)
  	    		origine << " is an element of map.\n";
  	  	else 
  	    	origine << " is not an element of map.\n";
  	}
	mymap ['a']=101;
  	mymap ['c']=202;
  	mymap ['f']=303;
  	
  	for (d='a'; d<'h'; d++)
  	{
  	  	my << d;
  	  	if (mymap.count(d)>0)
  	    		my << " is an element of map.\n";
  	  	else 
  	    	my << " is not an element of map.\n";
  	}
	std::string my_vector = my.str();
	std::string origine_vector = origine.str();
	std::cout << "Output cout: " << std::endl;
	std::cout << my_vector << std::endl;
	std::cout << origine_vector << std::endl;

	if (my_vector != origine_vector)
		return (1);
	return 0;
}
