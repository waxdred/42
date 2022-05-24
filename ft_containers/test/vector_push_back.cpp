/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_push_back.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 23:27:33 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/24 23:40:24 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

int main(void)
{
	std::stringstream my;
	std::stringstream origine;

	ft::vector<std::string> vector_str;
	std::vector<std::string> vector;

	std::cout << "check vector empty: " << (vector_str.empty() ? "true" : "false") << std::endl;
	std::cout << "size of vector: "<< vector_str.size() << std::endl;
	std::cout << "capacity of vector: "<< vector_str.capacity() << std::endl;
	my << "check vector empty: " << (vector_str.empty() ? "true" : "false") << std::endl;
	my << "size of vector: "<< vector_str.size() << std::endl;
	my << "capacity of vector: "<< vector_str.capacity() << std::endl;

	std::cout << "check vector empty: " << (vector_str.empty() ? "true" : "false") << std::endl;
	std::cout << "size of vector: "<< vector_str.size() << std::endl;
	std::cout << "capacity of vector: "<< vector_str.capacity() << std::endl;
	origine << "check vector empty: " << (vector_str.empty() ? "true" : "false") << std::endl;
	origine << "size of vector: "<< vector_str.size() << std::endl;
	origine << "capacity of vector: "<< vector_str.capacity() << std::endl;
	std::cout << std::endl;

	std::cout << std::endl << "0 push_back: " << std::endl;
	vector_str.push_back("salut");
	vector.push_back("salut");
	my << "size of vector: "<< vector_str.size() << std::endl;
	my << "capacity of vector: "<< vector_str.capacity() << std::endl;
	std::cout << "size of vector: "<< vector_str.size() << std::endl;
	std::cout << "capacity of vector: "<< vector_str.capacity() << std::endl;
	origine << "size of vector: "<< vector_str.size() << std::endl;
	origine << "capacity of vector: "<< vector_str.capacity() << std::endl;
	std::cout << "size of vector: "<< vector_str.size() << std::endl;
	std::cout << "capacity of vector: "<< vector_str.capacity() << std::endl;

	std::cout << std::endl << "push_back: " << std::endl;
	std::cout << std::endl;

	std::cout << std::endl << "1 push_back: " << std::endl;
	vector_str.push_back("a");
	vector.push_back("a");
	my << "size of vector: "<< vector_str.size() << std::endl;
	my << "capacity of vector: "<< vector_str.capacity() << std::endl;
	std::cout << "size of vector: "<< vector_str.size() << std::endl;
	std::cout << "capacity of vector: "<< vector_str.capacity() << std::endl;
	origine << "size of vector: "<< vector_str.size() << std::endl;
	origine << "capacity of vector: "<< vector_str.capacity() << std::endl;
	std::cout << "size of vector: "<< vector_str.size() << std::endl;
	std::cout << "capacity of vector: "<< vector_str.capacity() << std::endl;
	std::cout << std::endl << "push_back: " << std::endl;
	std::cout << std::endl;

	std::cout << std::endl << "2 push_back: " << std::endl;
	vector_str.push_back("toi");
	vector.push_back("toi");
	my << "size of vector: "<< vector_str.size() << std::endl;
	my << "capacity of vector: "<< vector_str.capacity() << std::endl;
	std::cout << "size of vector: "<< vector_str.size() << std::endl;
	std::cout << "capacity of vector: "<< vector_str.capacity() << std::endl;
	origine << "size of vector: "<< vector_str.size() << std::endl;
	origine << "capacity of vector: "<< vector_str.capacity() << std::endl;
	std::cout << "size of vector: "<< vector_str.size() << std::endl;
	std::cout << "capacity of vector: "<< vector_str.capacity() << std::endl;
	std::cout << std::endl << "push_back: " << std::endl;
	std::cout << std::endl;

	std::cout << std::endl << "3 push_back: " << std::endl;
	vector_str.push_back("\ncomment va tu?");
	vector.push_back("\ncomment va tu?");
	my << "size of vector: "<< vector_str.size() << std::endl;
	my << "capacity of vector: "<< vector_str.capacity() << std::endl;
	std::cout << "size of vector: "<< vector_str.size() << std::endl;
	std::cout << "capacity of vector: "<< vector_str.capacity() << std::endl;
	origine << "size of vector: "<< vector_str.size() << std::endl;
	origine << "capacity of vector: "<< vector_str.capacity() << std::endl;
	std::cout << "size of vector: "<< vector_str.size() << std::endl;
	std::cout << "capacity of vector: "<< vector_str.capacity() << std::endl;
	std::cout << std::endl << "push_back: " << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < 0; i++){
		vector_str.push_back("\ncomment va tu?");
		vector.push_back("\ncomment va tu?");
	}
	my << "size of vector: "<< vector_str.size() << std::endl;
	my << "capacity of vector: "<< vector_str.capacity() << std::endl;
	std::cout << "size of vector: "<< vector_str.size() << std::endl;
	std::cout << "capacity of vector: "<< vector_str.capacity() << std::endl;
	origine << "size of vector: "<< vector_str.size() << std::endl;
	origine << "capacity of vector: "<< vector_str.capacity() << std::endl;
	std::cout << "size of vector: "<< vector_str.size() << std::endl;
	std::cout << "capacity of vector: "<< vector_str.capacity() << std::endl;

	std::cout << vector_str << std::endl;
	std::string my_vector = my.str();
	std::string origine_vector = origine.str();
	if (my_vector != origine_vector)
		return (1);
	return 0;
}
