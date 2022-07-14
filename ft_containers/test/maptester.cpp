/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maptester.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:24:16 by jmilhas           #+#    #+#             */
/*   Updated: 2022/07/14 04:16:14 by jmilhas          ###   ########.fr       */
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
	t.insert(ft::pair<char, int>('e', 2));
	/* t.preOrder(t.getNode()); */
	ft::map<char, int>::iterator it = t.begin();
	for (int i; i < 4; i++, ++it)
		std::cout << it->first << ": " << it->second << std::endl;

	return 0;
}
