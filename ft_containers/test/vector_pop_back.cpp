/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_pop_back.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:00:08 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/25 20:37:10 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"

int main(void)
{
	std::stringstream my;
	std::stringstream origine;

	std::vector<int> myvector;
	ft::vector<int> vector;
  	int sum (0);
  	int m_sum (0);

  	myvector.push_back (100);
  	myvector.push_back (200);
  	myvector.push_back (300);

  	vector.push_back (100);
  	vector.push_back (200);
  	vector.push_back (300);

  	while (!myvector.empty())
  	{
  		sum += myvector.back();
  		myvector.pop_back();
  	}
  	while (!vector.empty())
  	{
  		m_sum += vector.back();
  		vector.pop_back();
  	}

  	std::cout << "The elements of vector add up to " << sum << '\n';
  	origine << "The elements add up to " << sum << '\n';

  	std::cout << "The elements of myvector add up to " << m_sum << '\n';
  	my << "The elements add up to " << m_sum << '\n';
	
	std::string my_vector = my.str();
	std::string origine_vector = origine.str();
	if (my_vector != origine_vector)
		return (1);
	return 0;
}
