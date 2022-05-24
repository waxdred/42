/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_clear.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 00:15:27 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/25 00:20:04 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"

int main(void)
{
	std::stringstream my;
	std::stringstream origine;
	
	ft::vector<std::string> vector_str;
	std::vector<std::string> vector;

	for (int i = 0; i < 5; i++){
		vector_str.push_back("salut");
		vector.push_back("salut");
		std::cout << vector_str[i] << std::endl;
		my << vector_str[i] << std::endl;
		std::cout << vector[i] << std::endl;
		origine << vector[i] << std::endl;
	}

	vector_str.resize(50, "test");
	vector.resize(50, "test");
	for (size_t i = 0; i < vector_str.size(); i++){
		std::cout << "vector: " << vector_str[i] << std::endl;
		my << "vector: " << vector_str[i] << std::endl;
	}
	for (size_t i = 0; i < vector.size(); i++){
		std::cout << "vector: " << vector[i] << std::endl;
		origine << "vector: " << vector[i] << std::endl;
	}

	std::cout << "size of vector: " << vector_str.size() << std::endl;
	std::cout << "capacity of vector: " << vector_str.capacity() << std::endl;
	std::cout << "clear of vector: " << std::endl;
	my << "size of vector: " << vector_str.size() << std::endl;
	my << "capacity of vector: " << vector_str.capacity() << std::endl;
	my << "clear of vector: " << std::endl;

	std::cout << "size of vector: " << vector.size() << std::endl;
	std::cout << "capacity of vector: " << vector.capacity() << std::endl;
	std::cout << "clear of vector: " << std::endl;
	origine << "size of vector: " << vector.size() << std::endl;
	origine << "capacity of vector: " << vector.capacity() << std::endl;
	origine << "clear of vector: " << std::endl;

	vector_str.clear();
	vector.clear();

	std::cout << "size of vector: " << vector_str.size() << std::endl;
	std::cout << "capacity of vector: " << vector_str.capacity() << std::endl;
	std::cout << vector_str.front();
	my << "size of vector: " << vector_str.size() << std::endl;
	my << "capacity of vector: " << vector_str.capacity() << std::endl;
	my << vector_str.front();

	std::cout << "size of vector: " << vector_str.size() << std::endl;
	std::cout << "capacity of vector: " << vector_str.capacity() << std::endl;
	std::cout << vector_str.front();
	origine << "size of vector: " << vector.size() << std::endl;
	origine << "capacity of vector: " << vector.capacity() << std::endl;
	origine << vector.front();
	std::string my_vector = my.str();
	std::string origine_vector = origine.str();
	if (my_vector != origine_vector)
		return (1);
	return 0;
}
