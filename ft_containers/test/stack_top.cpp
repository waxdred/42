/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_top.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:06:35 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/26 14:07:48 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"

int main(void)
{
	std::stringstream my;
	std::stringstream origine;
	
	std::stack<int> stack;
	ft::stack<int> mystack;

  	mystack.push(10);
  	mystack.push(20);
  	stack.push(10);
  	stack.push(20);
  	
  	mystack.top() -= 5;
  	stack.top() -= 5;
  	
  	std::cout << "mystack.top() is now " << mystack.top() << '\n';
  	std::cout << "mystack.top() is now " << stack.top() << '\n';
  	my << "mystack.top() is now " << mystack.top() << '\n';
  	origine << "mystack.top() is now " << stack.top() << '\n';

	std::string my_vector = my.str();
	std::string origine_vector = origine.str();
	std::cout << "Output cout: " << std::endl;
	std::cout << my_vector << std::endl;
	std::cout << origine_vector << std::endl;

	if (my_vector != origine_vector)
		return (1);
	return 0;
}
