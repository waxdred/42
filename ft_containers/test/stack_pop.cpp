/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:13:08 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/26 14:14:54 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"

int main(void)
{
	std::stringstream my;
	std::stringstream origine;
	
	std::stack<int> stack;
	ft::stack<int> mystack;

  	for (int i=0; i<5; ++i){
		mystack.push(i);
		stack.push(i);
	}

  	std::cout << "Popping out elements...";
  	while (!stack.empty())
  	{
  	   	std::cout << ' ' << stack.top();
  	   	origine << ' ' << stack.top();
  	   	stack.pop();
  	}
  	std::cout << '\n';

  	while (!mystack.empty())
  	{
  	   	std::cout << ' ' << mystack.top();
  	   	my << ' ' << mystack.top();
  	   	mystack.pop();
  	}
  	std::cout << '\n';

	std::string my_vector = my.str();
	std::string origine_vector = origine.str();
	std::cout << "Output cout: " << std::endl;
	std::cout << my_vector << std::endl;
	std::cout << origine_vector << std::endl;

	if (my_vector != origine_vector)
		return (1);
	return 0;
}
