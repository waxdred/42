/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:38:22 by jmilhas           #+#    #+#             */
/*   Updated: 2022/04/19 10:38:26 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*z = new Zombie("Yolo");

	z->annonce();
	delete z;
	z = newZombie("Todo");
	z->annonce();
	delete z;
	randomChump("Zoulou");
	return (0);
}
