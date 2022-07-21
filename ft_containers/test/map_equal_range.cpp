/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_equal_range.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:19:09 by jmilhas           #+#    #+#             */
/*   Updated: 2022/07/22 01:08:57 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"

int main(void)
{
	std::stringstream my;
	std::stringstream origine;
	
	std::map<char,int> map;
	ft::map<char,int> mymap;
	mymap['a']=10;
  	mymap['b']=20;
  	mymap['c']=30;
	map['a']=10;
  	map['b']=20;
  	map['c']=30;
  	
  	std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
  	ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> myret;
  	ret = map.equal_range('b');
  	myret = mymap.equal_range('b');
  	
  	origine << ret.first->first << " => " << ret.first->second << '\n';
  	my << myret.first->first << " => " << myret.first->second << '\n';
  	
  	origine << ret.second->first << " => " << ret.second->second << '\n';
  	my << myret.second->first << " => " << myret.second->second << '\n';

	std::string my_vector = my.str();
	std::string origine_vector = origine.str();
	std::cout << my_vector << std::endl;
	std::cout << origine_vector << std::endl;
	if (my_vector != origine_vector)
		return (1);
	return 0;
}
