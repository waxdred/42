/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 09:50:44 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/16 18:07:31 by jmilhas          ###   ########.fr       */
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
		std::string getName(void)const {return (this->_name);};
		int getAges(void) const{return (this->_ages);};
		bool getGenre(void) const{return (this->_genre);};
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
const T	min(const T a, const T b){
	if (a >= b)
		return (b);
	return (a);
}

template<typename T>
const T	max(const T a, const T b){
	if (a <= b)
		return (b);
	return (a);
}
#endif
