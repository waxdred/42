/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_access.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 00:22:16 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/25 00:29:24 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"

int main(void)
{
	std::stringstream my;
	std::stringstream origine;
	
	ft::vector<int> v;
	std::vector<int> vec;

	if (v.empty())
		std::cout << "test v.front() empty): " << v.front() << std::endl;
	for (int i = 0; i < 10; i++){
		v.push_back(i);
		vec.push_back(i);
	}
	v.push_back(12);
	vec.push_back(12);

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
	my << v.back() << std::endl;
	my << v.at(0) << std::endl;
	my << v.front() << std::endl;
	my << v[1] << std::endl;
	my << v.at(1) << std::endl;
	my << v[2] << std::endl;
	my << v.at(2) << std::endl;
	my << v.back() << std::endl;
	my << v.size() << std::endl;
	my << v.capacity() << std::endl;
	my << v.max_size() << std::endl;

	std::cout << "test last]: " << vec.back() << std::endl;
	std::cout << "test vec.at(0)): " << vec.at(0) << std::endl;
	std::cout << "test vec.front()): " << vec.front() << std::endl;
	std::cout << "test vec[1]]: " << vec[1] << std::endl;
	std::cout << "test vec.at(1)): " << vec.at(1) << std::endl;
	std::cout << "test vec[2]]: " << vec[2] << std::endl;
	std::cout << "test vec.at(2)): " << vec.at(2) << std::endl;
	std::cout << "test vec.back): " << vec.back() << std::endl;
	std::cout << "test vec.size(): " << vec.size() << std::endl;
	std::cout << "test vec.capacity(): " << vec.capacity() << std::endl;
	std::cout << "test vec.max_size(): " << vec.max_size() << std::endl;
	origine << vec.back() << std::endl;
	origine << vec.at(0) << std::endl;
	origine << vec.front() << std::endl;
	origine << vec[1] << std::endl;
	origine << vec.at(1) << std::endl;
	origine << vec[2] << std::endl;
	origine << vec.at(2) << std::endl;
	origine << vec.back() << std::endl;
	origine << vec.size() << std::endl;
	origine << vec.capacity() << std::endl;
	origine << vec.max_size() << std::endl;
	
	std::string my_vector = my.str();
	std::string origine_vector = origine.str();
	if (my_vector != origine_vector)
		return (1);
	return 0;
}
