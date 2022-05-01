/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 21:22:43 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/01 09:30:21 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
#include <iterator>

class outOfRange : public std::exception{
	public:
		const char *what() const throw(){
			return ("Out of range");
		}
};

/* @Brief Function iterator templates <T>*/
/* @Param1 <T> & container*/
/* @Param1 int n*/
/* @Return  (Iterator found)*/
template<typename T>
typename T::iterator easyfind(T &container, int n){
	typename T::iterator it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw outOfRange();
	return (it);
}

#endif
