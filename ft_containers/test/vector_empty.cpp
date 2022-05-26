/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_empty.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 20:43:32 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/25 20:46:06 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"

int main(void)
{
	std::stringstream my;
	std::stringstream origine;
	
	std::vector<int> vector;
	ft::vector<int> myvector;
  	int sum (0);
  	int msum (0);
  	
  	for (int i = 1; i <= 10; i++){
		myvector.push_back(i);
		vector.push_back(i);
	}
  	
  	while (!myvector.empty())
  	{
  	   	msum += myvector.back();
  	   	myvector.pop_back();
  	}
  	while (!vector.empty())
  	{
  	   	sum += vector.back();
  	   	vector.pop_back();
  	}

  	std::cout << "total: " << sum << '\n';
  	origine << "total: " << sum << '\n';

  	std::cout << "total: " << msum << '\n';
  	my << "total: " << msum << '\n';

	std::string my_vector = my.str();
	std::string origine_vector = origine.str();
	if (my_vector != origine_vector)
		return (1);
	return 0;
}
