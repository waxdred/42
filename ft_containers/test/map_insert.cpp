/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_insert.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 00:20:47 by jmilhas           #+#    #+#             */
/*   Updated: 2022/07/16 01:55:49 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"

int main(void)
{
	std::stringstream my;
	std::stringstream origine;
	
	std::map<char,int> map;
	ft::map<char,int> mymap;

  	// first insert function version (single parameter):
  	map.insert ( std::pair<char,int>('a',100) );
  	map.insert ( std::pair<char,int>('z',200) );
  	mymap.insert ( ft::pair<char,int>('a',100) );
  	mymap.insert ( ft::pair<char,int>('z',200) );
  	
  	std::pair<std::map<char,int>::iterator,bool> ret;
  	ft::pair<ft::map<char,int>::iterator,bool> myret;
  	ret = map.insert ( std::pair<char,int>('z',500) );
  	myret = mymap.insert ( ft::pair<char,int>('z',500) );
  	if (ret.second == false) {
  	  	origine << "element 'z' already existed";
  		origine << " with a value of " << ret.first->second << '\n';
  	}
  	
  	if (myret.second == false) {
  	  	my << "element 'z' already existed";
  		my << " with a value of " << ret.first->second << '\n';
  	}
  	// second insert function version (with hint position):
  	std::map<char,int>::iterator it = map.begin();
  	map.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
  	map.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting
  	
  	ft::map<char,int>::iterator myit = mymap.begin();
  	mymap.insert (myit, ft::pair<char,int>('b',300));  // max efficiency inserting
  	mymap.insert (myit, ft::pair<char,int>('c',400));  // no max efficiency inserting
  	// third insert function version (range insertion):
  	std::map<char,int> anothermap;
  	anothermap.insert(map.begin(),map.find('c'));
  	
  	ft::map<char,int> myanothermap;
  	myanothermap.insert(mymap.begin(),mymap.find('c'));
  	// showing contents:
  	std::cout << "map contains:\n";
  	for (it=map.begin(); it!=map.end(); ++it)
  	  	origine << it->first << " => " << it->second << '\n';
  	for (myit=mymap.begin(); myit!=mymap.end(); ++myit)
  	  	my << myit->first << " => " << myit->second << '\n';
  	
  	std::cout << "anothermap contains:\n";
  	for (it=anothermap.begin(); it!=anothermap.end(); ++it)
  	  	origine << it->first << " => " << it->second << '\n';
  	for (myit=myanothermap.begin(); myit!=myanothermap.end(); ++it)
  	  	my << myit->first << " => " << myit->second << '\n';

	std::string my_vector = my.str();
	std::string origine_vector = origine.str();
	if (my_vector != origine_vector)
		return (1);
	return 0;
}
