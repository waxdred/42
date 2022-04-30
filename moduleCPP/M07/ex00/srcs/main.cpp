/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 09:50:24 by jmilhas           #+#    #+#             */
/*   Updated: 2022/04/30 11:35:43 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "whatever.hpp"

int main(void)
{
	{
		Perso p1("todo", 18, true);
		Perso p2("foo", 42, false);
		char	a = 'c';
		char	b = 'e';
		int	c = 42;
		int	d = 0;

		std::cout << "Swap\n" << std::endl;
		std::cout << "before swap char: \n\ta = '" << a << "'\n\tb = '" << b << "'" << std::endl;
		swap(a, b);
		std::cout << "after swap char: \n\ta = '" << a << "'\n\tb = '" << b << "'" << std::endl << std::endl;
		std::cout << "before swap int: \n\tc = '" << c << "'\n\td = '" << d << "'" << std::endl;
		swap(c, d);
		std::cout << "after swap int: \n\tc = '" << c << "'\n\td = '" << d << "'\n" << std::endl;
		
		std::cout << "Swap class Perso\n" << std::endl;
		std::cout << "P1" << std::endl;
		p1.printClass();
		std::cout << "P2" << std::endl;
		p2.printClass();
		std::cout << "swap" << std::endl;
		swap(p1, p2);
		std::cout << "P1" << std::endl;
		p1.printClass();
		std::cout << "P2" << std::endl;
		p2.printClass();

		std::cout << "\nMin" << std::endl;
		std::cout << "min of: " << a << " | " << b << " = " <<  min(a, b) << std::endl;
		std::cout << "min of: " << c << " | " << d << " = " <<  min(c, d) << std::endl;

		std::cout << "\nMax" << std::endl;
		std::cout << "Max of: " << a << " | " << b << " = " <<  max(a, b) << std::endl;
		std::cout << "Max of: " << c << " | " << d << " = " <<  max(c, d) << std::endl;
	}
	{
		std::cout << "\n\nMain 42 " << std::endl;
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	return 0;
}
