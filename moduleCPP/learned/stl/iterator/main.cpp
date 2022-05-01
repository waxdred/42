/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 16:50:46 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/01 18:19:04 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <stack>
#include <initializer_list>

int	main()
{
#if 0
	std::vector<int> vec;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);

	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++){
		std::cout << it.base() << std::endl;
		std::cout << *it << std::endl;
	}
#endif
}
