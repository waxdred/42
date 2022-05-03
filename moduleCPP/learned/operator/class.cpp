/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 17:54:19 by jmilhas           #+#    #+#             */
/*   Updated: 2022/04/30 18:35:24 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class.hpp"

Perso::Perso(void){
	return ;
}

Perso::Perso(const std::string &names, int ages, bool gender)
	:_name(names), _ages(ages), _gender(gender){
		return ;
}

Perso::~Perso(void){
	return ;
}

Perso::Perso(const Perso &perso){
	*this = perso;
}

std::string	Perso::getName(void)const{
	return  (this->_name);
}

int		Perso::getAges(void)const{
	return (this->_ages);
}

bool		Perso::getgender(void)const{
	return (this->_gender);
}

Perso &Perso::operator = (const Perso &perso){
	if (&perso != this){
		this->_name = perso._name;
		this->_ages = perso._ages;
		this->_gender = perso._gender;
	}
	return (*this);
}

void Perso::operator + (Perso &perso){
	if (this->_ages <= 42){
		std::cout << "Happy Birthday to you!" << std::endl << perso;
	}
	else
		throw errorYouToOld();
	this->_ages++;
}

const char *Perso::errorYouToOld::what() const throw(){
	return ("Ho my god you so old!!!!!!");
}

std::ostream &operator<<(std::ostream &o, const Perso &p){
	o << "name: " << p.getName() << "\nages: " << p.getAges() << "\ngender: "\
		<< (p.getgender() ? "Males" : "Female")<<std::endl;
	return (o);
}
