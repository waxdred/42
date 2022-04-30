/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_cast.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 09:04:39 by jmilhas           #+#    #+#             */
/*   Updated: 2022/04/29 09:10:04 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

int main(void)
{
	int 		a = 42;
	int const 	*b = &a;
	/* int 		*c = b; compilation fail */ 
	int		*c = const_cast<int *>(b);

	std::cout << "int		a = 42: " << a << std::endl;
	std::cout << "int const 	*b = &a: " << b << std::endl;
	std::cout << "int  		*c = &b: " << "Eror compilation cannot work" << std::endl;
	std::cout << "int		*c = const_cast<int *>(b):" << *c << std::endl;

	return 0;
}
