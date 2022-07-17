/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_swap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 08:33:45 by jmilhas           #+#    #+#             */
/*   Updated: 2022/07/17 08:37:22 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"

int main(void)
{
	std::stringstream my;
	std::stringstream origine;
	std::map<char,int> foo,bar;

  	foo['x']=100;
  	foo['y']=200;
  	
  	bar['a']=11;
  	bar['b']=22;
  	bar['c']=33;
  	
  	foo.swap(bar);
  	
  	std::cout << "foo contains:\n";
  	for (std::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
  	  	origine << it->first << " => " << it->second << '\n';
  	
  	std::cout << "bar contains:\n";
  	for (std::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
  	  	origine << it->first << " => " << it->second << '\n';


	ft::map<char,int> myfoo,mybar;

  	myfoo['x']=100;
  	myfoo['y']=200;

  	mybar['a']=11;
  	mybar['b']=22;
  	mybar['c']=33;

  	myfoo.swap(mybar);

  	std::cout << "foo contains:\n";
  	for (ft::map<char,int>::iterator myit=myfoo.begin(); myit!= myfoo.end(); ++myit)
  	  	my << myit->first << " => " << myit->second << '\n';

  	std::cout << "bar contains:\n";
  	for (ft::map<char,int>::iterator myit=mybar.begin(); myit!=mybar.end(); ++myit)
  	  	my << myit->first << " => " << myit->second << '\n';

	std::string my_vector = my.str();
	std::string origine_vector = origine.str();
	std::cout << "Output cout: " << std::endl;
	std::cout << my_vector << std::endl;
	std::cout << origine_vector << std::endl;

	if (my_vector != origine_vector)
		return (1);
	return 0;
}
