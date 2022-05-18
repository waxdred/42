/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:33:06 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/18 14:57:17 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_iterator.hpp"
#include <iostream>
#include <ostream>
#include <string>
#include <deque>
#include <map.hpp>
#include <stack.hpp>
#include <vector.hpp>
#include <stdlib.h>

void 	ft_test_push_back(void);
void   ft_test_acces_element(void);
void   ft_clear(void);
void 	ft_resize(void);
void	ft_iterator(void);

int main(void)
{
	/* ft_test_acces_element(); */
	/* ft_test_push_back(); */ 
	/* ft_clear(); */
	/* ft_resize(); */
	ft_iterator();
	return 0;
}

void	ft_iterator(void){
	ft::vector<std::string> v;
	std::string val =  "salut: ";

	std::cout <<  "Iterator empty\n" << v << std::endl;
	for (int i = 1; i < 11; i++)
	{
		val.append(std::to_string(i));
		v.push_back(val);
	}
	std::cout <<  "Iterator\n" << v << std::endl;

}

void ft_resize(void){
	ft::vector<int> myvector;

	for (int i=1;i<10;i++) myvector.push_back(i);
	
	myvector.resize(5);
	std::cout << myvector.size() << std::endl;
	myvector.resize(8,100);
	myvector.resize(12);
	
	std::cout << "myvector contains:";
	for (size_t i=0; i < myvector.size(); i++)
	  std::cout << ' ' << myvector[i];
	std::cout << '\n';
}

void   ft_clear(void){
	ft::vector<std::string> vector_str;

	for (int i = 0; i < 5; i++){
		vector_str.push_back("salut");
		std::cout << vector_str[i] << std::endl;
	}
	vector_str.resize(50, "test");
	for (size_t i = 0; i < vector_str.size(); i++)
		std::cout << "vector: " << vector_str[i] << std::endl;
	std::cout << "size of vector: " << vector_str.size() << std::endl;
	std::cout << "capacity of vector: " << vector_str.capacity() << std::endl;
	std::cout << "clear of vector: " << std::endl;
	/* vector_str.clear(); */
	/* std::cout << "size of vector: " << vector_str.size() << std::endl; */
	/* std::cout << "capacity of vector: " << vector_str.capacity() << std::endl; */
	/* std::cout << vector_str.front(); */
}

void   ft_test_acces_element(void){
	ft::vector<int> v;

	if (v.empty())
		std::cout << "test v.front() empty): " << v.front() << std::endl;
	for (int i = 0; i < 10; i++){
		v.push_back(i);
	}
	v.push_back(12);
	std::cout << "test last]: " << v.back() << std::endl;
	std::cout << "test v.at(0)): " << v.at(0) << std::endl;
	std::cout << "test v.front()): " << v.front() << std::endl;
	std::cout << "test v[1]]: " << v[1] << std::endl;
	std::cout << "test v.at(1)): " << v.at(1) << std::endl;
	std::cout << "test v[2]]: " << v[2] << std::endl;
	std::cout << "test v.at(2)): " << v.at(2) << std::endl;
	std::cout << "test v.back): " << v.back() << std::endl;
	std::cout << "test v.size(): " << v.size() << std::endl;
	std::cout << "test v.capacity(): " << v.capacity() << std::endl;
	std::cout << "test v.max_size(): " << v.max_size() << std::endl;
	
}

void 	ft_test_push_back(void){
	ft::vector<std::string> vector_str;

	std::cout << "check vector empty: " << (vector_str.empty() ? "true" : "false") << std::endl;
	std::cout << "size of vector: "<< vector_str.size() << std::endl;
	std::cout << "capacity of vector: "<< vector_str.capacity() << std::endl;
	std::cout << std::endl;

	std::cout << std::endl << "0 push_back: " << std::endl;
	vector_str.push_back("salut");
	std::cout << "size of vector: "<< vector_str.size() << std::endl;
	std::cout << "capacity of vector: "<< vector_str.capacity() << std::endl;
	std::cout << std::endl << "push_back: " << std::endl;
	std::cout << std::endl;


	std::cout << std::endl << "1 push_back: " << std::endl;
	vector_str.push_back("a");
	std::cout << "size of vector: "<< vector_str.size() << std::endl;
	std::cout << "capacity of vector: "<< vector_str.capacity() << std::endl;
	std::cout << std::endl << "push_back: " << std::endl;
	std::cout << std::endl;

	std::cout << std::endl << "2 push_back: " << std::endl;
	vector_str.push_back("toi");
	std::cout << "size of vector: "<< vector_str.size() << std::endl;
	std::cout << "capacity of vector: "<< vector_str.capacity() << std::endl;
	std::cout << std::endl << "push_back: " << std::endl;
	std::cout << std::endl;

	std::cout << std::endl << "3 push_back: " << std::endl;
	vector_str.push_back("\ncomment va tu?");
	std::cout << "size of vector: "<< vector_str.size() << std::endl;
	std::cout << "capacity of vector: "<< vector_str.capacity() << std::endl;
	std::cout << std::endl << "push_back: " << std::endl;
	std::cout << std::endl;

	std::cout << vector_str[0] << std::endl;
	std::cout << vector_str[1] << std::endl;
	std::cout << vector_str[2] << std::endl;
	std::cout << vector_str[3] << std::endl;
}


