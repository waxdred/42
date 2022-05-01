/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 15:27:31 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/01 15:37:09 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>

template<typename T>
void	print(std::stack<T> stk){
	while (!stk.empty()){
		std::cout << stk.top() << std::endl;
		stk.pop();
	}
}

int main()
{
	std::stack<int> stk;
	
	stk.push(4);
	stk.push(3);
	stk.push(2);

	print(stk);
	print(stk);
}
