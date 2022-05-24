/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:33:06 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/25 00:34:22 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "vector_iterator.hpp"
#include <iostream>
#include <vector>
#include <sstream>

int main(void)
{
	ft::vector<int> foo (3,100);   // three ints with a value of 100
	ft::vector<int> bar (5,200);   // five ints with a value of 200

	  foo.swap(bar);

	  std::cout << "foo contains:";
	  for (unsigned i=0; i<foo.size(); i++)
	    std::cout << ' ' << foo[i];
	  std::cout << '\n';

	  std::cout << "bar contains:";
	  for (unsigned i=0; i<bar.size(); i++)
	    std::cout << ' ' << bar[i];
	  std::cout << '\n';

	return 0;
}


