/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maptester.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:24:16 by jmilhas           #+#    #+#             */
/*   Updated: 2022/07/10 23:04:28 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.hpp"
#include <utility>

int main(void)
{
	ft::map<char, int> t;
	t.insert(ft::pair<char, int>('a', 0));
	t.insert(ft::pair<char, int>('s', 4));
	t.insert(ft::pair<char, int>('b', 1));
	t.insert(ft::pair<char, int>('y', 4));
	t.insert(ft::pair<char, int>('c', 2));
	ft::map<char, int>::iterator it = t.begin();
	std::cout << it->first << std::endl;
	++it;
	std::cout << it->first << std::endl;

	return 0;
}
