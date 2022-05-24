/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_resize.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 00:05:15 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/25 00:11:37 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"

int main(void)
{
	std::stringstream my;
	std::stringstream origine;

	ft::vector<int> myvector;
	std::vector<int> vector;

	for (int i=1;i<10;i++){
		myvector.push_back(i);
		vector.push_back(i);
	}
	
	myvector.resize(5);
	vector.resize(5);
	std::cout << myvector.size() << std::endl;
	my << myvector.size() << std::endl;
	std::cout << vector.size() << std::endl;
	origine << vector.size() << std::endl;
	myvector.resize(8,100);
	myvector.resize(12);
	vector.resize(8,100);
	vector.resize(12);
	
	for (size_t i=0; i < myvector.size(); i++){
		std::cout << ' ' << myvector[i];
		my << ' ' << myvector[i];
	}
	std::cout << '\n';
	for (size_t i=0; i < vector.size(); i++){
		std::cout << ' ' << vector[i];
		origine << ' ' << myvector[i];
	}
	std::cout << '\n';
	
	std::string my_vector = my.str();
	std::string origine_vector = origine.str();
	if (my_vector != origine_vector)
		return (1);
	return 0;
}
