/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:39:12 by jmilhas           #+#    #+#             */
/*   Updated: 2022/04/19 10:39:19 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _Name(name){
}

Zombie::~Zombie(void)
{
	std::cout << "Destroyed Zombie" << std::endl;
}

void	Zombie::set_name(std::string name)
{
	this->_Name = name;
}

std::string	Zombie::get_name(void) const
{
	return (this->_Name);
}

void	Zombie::annonce(void){
	std::cout << _Name << ": " <<  "BraiiiiiiinnnzzzZ..." << std::endl;
}
