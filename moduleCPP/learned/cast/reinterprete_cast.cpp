/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reinterprete_cast.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 08:57:04 by jmilhas           #+#    #+#             */
/*   Updated: 2022/04/29 09:03:51 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	float a = 45.454f;

	void *b = &a;
	int *c = reinterpret_cast<int *>(b);
	int &d = reinterpret_cast<int &>(b);

	std::cout << "float: " << a << std::endl;
	std::cout << "void : " << b << std::endl;
	std::cout << "int*: " <<  c << std::endl;
	std::cout << "int&: " << d << std::endl;

	std::cout << "Les reinterpret_cast permet de de retype le cast il n'y aura pas d'erreur sur la compilation donc faire attention:" << std::endl;
	return 0;
}
