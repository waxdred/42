/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_swap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 23:41:40 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/24 23:57:51 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

int main(void)
{
	ft::vector<int> foo (3,100);   // three ints with a value of 100
	ft::vector<int> bar (5,200);   // five ints with a value of 200
	std::vector<int> v_foo (3,100);   // three ints with a value of 100
	std::vector<int> v_bar (5,200);   // five ints with a value of 200
	std::stringstream my;
	std::stringstream origine;

 	foo.swap(bar);
 	v_foo.swap(v_bar);

  	std::cout << "foo contains:";
  	for (unsigned i=0; i<foo.size(); i++)
	{
    		std::cout << ' ' << foo[i];
    		my << ' ' << foo[i];
	}
  	for (unsigned i=0; i<v_foo.size(); i++)
	{
    		std::cout << ' ' << v_foo[i];
    		origine << ' ' << v_foo[i];
	}
  	std::cout << '\n';
  	my << '\n';
  	origine << '\n';

  	std::cout << "bar contains:";
  	for (unsigned i=0; i<bar.size(); i++){
    		std::cout << ' ' << bar[i];
    		my << ' ' << bar[i];
	}
  	std::cout << '\n';
  	for (unsigned i=0; i<v_bar.size(); i++){
    		std::cout << ' ' << v_bar[i];
    		origine << ' ' << v_bar[i];
	}
  	std::cout << '\n';
	std::string my_vector = my.str();
	std::string origine_vector = origine.str();
	if (my_vector != origine_vector)
		return (1);

	return 0;
}
