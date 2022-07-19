/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_operator.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 02:34:15 by jmilhas           #+#    #+#             */
/*   Updated: 2022/07/19 02:41:28 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"

int main(void)
{
	std::stringstream my;
	std::stringstream origine;
	
	std::map<char,int> first;
  	std::map<char,int> second;
	ft::map<char,int> myfirst;
  	ft::map<char,int> mysecond;
  	
  	first['x']=8;
  	first['y']=16;
  	first['z']=32;
  	myfirst['x']=8;
  	myfirst['y']=16;
  	myfirst['z']=32;
  	
  	second=first;                // second now contains 3 ints
  	mysecond=myfirst;                // second now contains 3 ints
	/* ft::map<char, int> t = myfirst; */

  	first=std::map<char,int>();  // and first is now empty
  	myfirst=ft::map<char,int>();  // and first is now empty
  	
  	origine << "Size of first: " << first.size() << '\n';
  	origine << "Size of second: " << second.size() << '\n';
  	my << "Size of first: " << myfirst.size() << '\n';
  	my << "Size of second: " << mysecond.size() << '\n';
	std::string my_vector = my.str();
	std::string origine_vector = origine.str();
	if (my_vector != origine_vector)
		return (1);
	return 0;
}
