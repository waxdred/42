/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 10:07:20 by jmilhas           #+#    #+#             */
/*   Updated: 2022/04/29 18:10:17 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cast.hpp"

int main(int ac, char **av)
{
	if (ac != 2){
		std::cerr << "Error:\n\tNeed 1 argument" << std::endl;
		return (-1);
	}
	Cast	cast(av[1]);
	cast.printConv();
	return 0;
}
