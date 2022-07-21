/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 11:04:07 by jmilhas           #+#    #+#             */
/*   Updated: 2022/07/22 00:41:16 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/map.hpp"

int main(void)
{
	ft::map<int, int> m;

	m[5] = 5;
	m[4] = 4;
	m[9] = 9;
	m[3] = 3;
	m[7] = 7;
	m[6] = 6;
	m[8] = 8;
	
	std::cout << "before" << std::endl;
	for (ft::map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
		std::cout << it->first << std::endl;
	int r= 3;
	ft::map<int, int>::iterator it;
	std::cout << "a => " << m.find(r)->second << '\n';
	return 0;
}
