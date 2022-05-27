/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_empty.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:56:16 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/26 14:02:25 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"

int main(void)
{
	std::stringstream my;
	std::stringstream origine;
	
	std::stack<int> stack;
	ft::stack<int> mystack;
	int sum (0);
	int msum (0);

  	for (int i=1; i <= 10; i++){
		mystack.push(i);
		stack.push(i);
	}

  	while (!stack.empty())
  	{
     		sum += stack.top();
     		stack.pop();
  	}
  	while (!mystack.empty())
  	{
     		msum += mystack.top();
     		mystack.pop();
  	}
  	std::cout << "total: " << sum << '\n';
  	origine << "total: " << sum << '\n';

  	std::cout << "total: " << msum << '\n';
  	my << "total: " << msum << '\n';
	std::string my_vector = my.str();
	std::string origine_vector = origine.str();
	std::cout << "Output cout: " << std::endl;
	std::cout << my_vector << std::endl;
	std::cout << origine_vector << std::endl;

	if (my_vector != origine_vector)
		return (1);
	return 0;
}
