/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explicit.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 09:28:39 by jmilhas           #+#    #+#             */
/*   Updated: 2022/04/29 09:46:14 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class A{};
class B{};
class C{
	public:
		C(A const &_){
			return;
		}
		explicit C(B const &_){
			return;
		}
};

void f(C const &_){
	return;
}

int main(void)
{
	std::cout << "ajouter explicite dans une fonction de class permet de évité les cast inplicites" << std::endl;
	f(A());
	f(static_cast<C>(B)());
	return 0;
}
