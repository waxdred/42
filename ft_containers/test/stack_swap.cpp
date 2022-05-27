/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:16:09 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/26 14:17:45 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"

int main(void)
{
	std::stringstream my;
	std::stringstream origine;
	
	std::stack<int> foo, bar;
	ft::stack<int> mfoo, mbar;
  	foo.push (10); foo.push(20); foo.push(30);
  	bar.push (111); bar.push(222);
  	mfoo.push (10); mfoo.push(20); mfoo.push(30);
  	mbar.push (111); mbar.push(222);

  	foo.swap(bar);
  	mfoo.swap(mbar);

  	std::cout << "size of foo: " << foo.size() << '\n';
  	std::cout << "size of bar: " << bar.size() << '\n';
  	origine << "size of foo: " << foo.size() << '\n';
  	origine << "size of bar: " << bar.size() << '\n';
  	
	std::cout << "size of foo: " << foo.size() << '\n';
  	std::cout << "size of bar: " << bar.size() << '\n';
  	my << "size of foo: " << foo.size() << '\n';
  	my << "size of bar: " << bar.size() << '\n';

	std::string my_vector = my.str();
	std::string origine_vector = origine.str();
	std::cout << "Output cout: " << std::endl;
	std::cout << my_vector << std::endl;
	std::cout << origine_vector << std::endl;

	if (my_vector != origine_vector)
		return (1);
	return 0;
}
