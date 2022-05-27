/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_insert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:32:12 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/27 14:58:55 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"

int main(void)
{
	std::stringstream my;
	std::stringstream origine;
	
	ft::vector<int> vector (3,100);
  	ft::vector<int>::iterator mit;
  	
  	mit = vector.begin();
  	mit = vector.insert ( mit , 200 );
  	
  	vector.insert (mit,2,300);
  	
  	// "mit" no longer valid, get a new one:
  	mit = vector.begin();
  	
  	std::vector<int> anothervector (2,400);
  	vector.insert (mit+2,anothervector.begin(),anothervector.end());
  	
  	int array [] = { 501,502,503 };
  	vector.insert (vector.begin(), array, array+3);
  	
  	std::cout << "myvector contains:";
  	for (mit=vector.begin(); mit<vector.end(); mit++){
    		std::cout << ' ' << *mit;
    		my << ' ' << *mit;
	}
  	std::cout << '\n';
	std::vector<int> myvector (3,100);
  	std::vector<int>::iterator it;

  	it = myvector.begin();
  	it = myvector.insert ( it , 200 );

  	myvector.insert (it,2,300);

  	// "it" no longer valid, get a new one:
  	it = myvector.begin();

  	std::vector<int> tvector (2,400);
  	myvector.insert (it+2, tvector.begin(), tvector.end());

  	int myarray [] = { 501,502,503 };
  	myvector.insert (myvector.begin(), myarray, myarray+3);

  	std::cout << "vector contains:";
  	for (it=myvector.begin(); it<myvector.end(); it++){
  	  	std::cout << ' ' << *it;
  	  	origine << ' ' << *it;
	}
  	std::cout << '\n';

	std::string _vector = my.str();
	std::string origine_vector = origine.str();
	std::cout << "Output cout: " << std::endl;
	std::cout << _vector << std::endl;
	std::cout << origine_vector << std::endl;

	if (_vector != origine_vector)
		return (1);
	return 0;
}
