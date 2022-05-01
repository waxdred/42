/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 15:38:50 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/01 19:56:01 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.cpp"

int main(void)
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	/* //[...] */
	mstack.push(0);
	/* MutantStack<int>::iterator it = mstack.begin(); */
	/* MutantStack<int>::iterator ite = mstack.end(); */
	/* /1* ++it; *1/ */
	/* /1* --it; *1/ */
	/* /1* while (it != ite) *1/ */
	/* /1* { *1/ */
	/* /1* std::cout << *it << std::endl; *1/ */
	/* /1* ++it; *1/ */
	/* /1* } *1/ */
	std::stack<int> s(mstack);
	
	return 0;
}
