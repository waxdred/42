/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 00:39:39 by jmilhas           #+#    #+#             */
/*   Updated: 2022/04/30 00:57:51 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>

void print(const std::string &c){
	std::cout << c << std::endl;
}

int main(void)
{
	std::vector<std::string> tab;
	std::vector<double>::const_iterator i;

	tab.push_back("salut");
	tab.push_back(" a ");
	tab.push_back("toi");
	tab.push_back("? ");
	
	std::for_each(tab.begin(), tab.end(), print);

	return 0;
}
