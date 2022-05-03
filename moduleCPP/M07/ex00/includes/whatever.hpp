/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 09:50:44 by jmilhas           #+#    #+#             */
/*   Updated: 2022/04/30 11:31:42 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

class Perso{
	private:
		std::string 	_name;
		int		_ages;
		bool		_genre;
	public:
		Perso(void);
		~Perso(void);
		Perso(const std::string name, const int ages, const bool genre);
		std::string getName(void){return (this->_name);};
		int getAges(void){return (this->_ages);};
		bool getGenre(void){return (this->_genre);};
		void printClass(void)const;
};


template<typename T>
void	swap(T&a, T&b){
	T	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T	min(T a, T b){
	if (a >= b)
		return (b);
	return (a);
}

template<typename T>
T	max(T a, T b){
	if (a <= b)
		return (b);
	return (a);
}
#endif
