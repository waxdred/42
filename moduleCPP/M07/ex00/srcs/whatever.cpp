/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 11:10:11 by jmilhas           #+#    #+#             */
/*   Updated: 2022/04/30 11:20:20 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

Perso::Perso(const std::string name, const int ages, const bool genre)
	:_name(name), _ages(ages), _genre(genre){
			return; };

void Perso::printClass(void)const{
	std::cout << "name: "<< _name << "\nages: " << _ages << "\ngenre: " << (_genre ? "Male" : "Female") << std::endl;
};

Perso::Perso(void){
	return;
}

Perso::~Perso(void){
	return;
}
