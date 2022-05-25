/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_pair.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:21:01 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/25 10:58:44 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"
#include <utility>      // std::pair, std::make_pair
#include <string> 

int main(void)
{
	std::stringstream my;
	std::stringstream origine;

	std::pair <std::string,double> product1;                     // default constructor
  	std::pair <std::string,double> product2 ("tomatoes",2.30);   // value init
  	std::pair <std::string,double> product3 (product2);          // copy constructor
  	
  	product1 = std::make_pair(std::string("lightbulbs"),0.99);   // using make_pair (move)
  	
  	product2.first = "shoes";                  // the type of first is string
  	product2.second = 39.90;                   // the type of second is double
  	
  	std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
  	std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
  	std::cout << "The price of " << product3.first << " is $" << product3.second << '\n';
  	origine << "The price of " << product1.first << " is $" << product1.second << '\n';
  	origine << "The price of " << product2.first << " is $" << product2.second << '\n';
  	origine << "The price of " << product3.first << " is $" << product3.second << '\n';
	
	ft::pair <std::string,double> m_product1;                     // default constructor
  	ft::pair <std::string,double> m_product2 ("tomatoes",2.30);   // value init
  	ft::pair <std::string,double> m_product3 (m_product2);          // copy constructor
  	
  	m_product1 = ft::make_pair(std::string("lightbulbs"),0.99);   // using make_pair (move)
  	m_product2.first = "shoes";                  // the type of first is string
  	m_product2.second = 39.90;                   // the type of second is double
  	
  	std::cout << "The price of " << m_product1.first << " is $" << m_product1.second << '\n';
  	std::cout << "The price of " << m_product2.first << " is $" << m_product2.second << '\n';
  	std::cout << "The price of " << m_product3.first << " is $" << m_product3.second << '\n';
  	my << "The price of " << m_product1.first << " is $" << m_product1.second << '\n';
  	my << "The price of " << m_product2.first << " is $" << m_product2.second << '\n';
  	my << "The price of " << m_product3.first << " is $" << m_product3.second << '\n';


	// test makepair
	std::pair <int,int> foo;
  	std::pair <int,int> bar;
  
   	foo = std::make_pair (10,20);
   	bar = std::make_pair (10.5,'A'); // ok: implicit conversion from pair<double,char>
   	
   	std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
   	std::cout << "bar: " << bar.first << ", " << bar.second << '\n';
   	origine << "foo: " << foo.first << ", " << foo.second << '\n';
   	origine << "bar: " << bar.first << ", " << bar.second << '\n';

	ft::pair <int,int> m_foo;
  	ft::pair <int,int> m_bar;
  
   	m_foo = ft::make_pair (10,20);
   	m_bar = ft::make_pair (10.5,'A'); // ok: implicit conversion from pair<double,char>
   	
   	std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
   	std::cout << "bar: " << bar.first << ", " << bar.second << '\n';
   	my << "foo: " << foo.first << ", " << foo.second << '\n';
   	my << "bar: " << bar.first << ", " << bar.second << '\n';

	std::string my_vector = my.str();
	std::string origine_vector = origine.str();
	std::cout << "Output cout: " << std::endl;
	std::cout << my_vector << std::endl;
	std::cout << origine_vector << std::endl;

	if (my_vector != origine_vector)
		return (1);
	return 0;
}
