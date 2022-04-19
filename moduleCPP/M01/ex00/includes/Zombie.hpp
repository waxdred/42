/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:39:26 by jmilhas           #+#    #+#             */
/*   Updated: 2022/04/19 10:39:28 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

class	Zombie
{
	private:
		std::string _Name;
	public:
		Zombie(std::string name);
		void		set_name(std::string name);
		std::string	get_name(void) const;
		void	annonce(void);
		~Zombie(void);
};
void	randomChump(std::string name);
Zombie	*newZombie(std::string name);
#endif
