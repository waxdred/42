/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_iterator.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:22:32 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/25 18:17:11 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"

int main(void)
{
	std::stringstream my;
	std::stringstream origine;
	
	//rbegin test
	std::vector<int> myvector (5);  // 5 default-constructed ints
	ft::vector<int> vector (5);  // 5 default-constructed ints

  	std::vector<int>::reverse_iterator rit = myvector.rbegin();
	ft::reverse_iterator m_rit = vector.rbegin();
  	for (int i = 0; rit!= myvector.rend(); ++rit)
  		*rit = ++i;
  	for (int i = 0; m_rit != vector.rend(); m_rit++)
  		*m_rit = ++i;

  	std::cout << "vector contains:";
  	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it){
  	  	std::cout << ' ' << *it;
  	  	origine << ' ' << *it;
	}
  	std::cout << '\n';
  	std::cout << "myvector contains:";
  	for (ft::iterator it = vector.begin(); it != vector.end(); it++){
  	  	std::cout << ' ' << *it;
  	  	my << ' ' << *it;
	}
  	std::cout << '\n';


	//rend test
	std::vector<int> r_myvector (5);  // 5 default-constructed ints
	ft::vector<int> r_vector (5);  // 5 default-constructed ints

  	std::vector<int>::reverse_iterator rrit = myvector.rbegin();
  	ft::reverse_iterator rm_rit = r_vector.rbegin();

	int i = 0;
  	for (rrit = r_myvector.rbegin(); rrit!= myvector.rend(); ++rrit)
  	  	*rrit = ++i;
	i = 0;
  	for (rm_rit = r_vector.rbegin(); rm_rit != r_vector.rend(); rm_rit++){
  	  	*rm_rit = ++i;
	}

  	std::cout << "vector contains:";
  	for (std::vector<int>::iterator it = r_myvector.begin(); it != r_myvector.end(); ++it){
  	  	std::cout << ' ' << *it;
  	  	origine << ' ' << *it;
	}
  	std::cout << '\n';
  	std::cout << "myvector contains:";
  	for (ft::iterator it = r_vector.begin(); it != r_vector.end(); it++){
  	  	std::cout << ' ' << *it;
  	  	my << ' ' << *it;
	}
  	std::cout << '\n';
	
	//const rbegin
	
	std::string my_vector = my.str();
	std::string origine_vector = origine.str();
	if (my_vector != origine_vector)
		return (1);
	return 0;
}
