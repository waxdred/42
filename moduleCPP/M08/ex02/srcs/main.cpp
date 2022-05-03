/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 15:38:50 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/03 08:52:19 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.cpp"
#include "MutantStack.hpp"
#include <algorithm>

/* static void print(const int &a){ */
/* 	std::cout << "stack: "<< a << std::endl; */
/* } */

int main(void)
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "top stack: " << std::endl;
	std::cout << mstack.top() << std::endl;
	std::cout << "pop stack: plus acces a 17" << std::endl;
	mstack.pop();
	std::cout << "size stack: " << std::endl;
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int> t = mstack;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	std::cout << "iterate stack" << std::endl;
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	
	return 0;
}
