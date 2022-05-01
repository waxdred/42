/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 21:22:43 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/01 09:30:14 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <algorithm>

/*
@Brief Push back int value until size
@Param1 std::veector &v
@Param1 int n
@Return  Return NONE*/
template<typename T>
void  	addVector(std::vector<T> &v, int n){
	for (int i = 0; i < n; i++){
		v.push_back(i);
	}
}

int main(void)
{
	std::vector<int> v;

	addVector(v, 10);

	try{
		std::cout << *easyfind(v, 9) << std::endl;
		std::cout << *easyfind(v, 10)<< std::endl;
		std::cout << *easyfind(v, 42)<< std::endl;
	}catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	return 0;
}
