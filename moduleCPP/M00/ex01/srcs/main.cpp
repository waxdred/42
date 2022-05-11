/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 20:03:22 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/07 14:55:41 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

static  void	ft_menu(void)
{
	std::cout << "Available commands:" << std::endl;
	std::cout << "\tADD" << std::endl;
	std::cout << "\tSEARCH" << std::endl;
	std::cout << "\tEXIT" << std::endl;
	std::cout << std::endl;
	std::cout << "--> ";
}

int8_t	ft_while(PhoneBook &phone){
	std::string	buff;
	std::string 	cmd;
	int		index = 0;
	int 		ret = 0;

	while (!ret){
		ft_menu();
		if (index == NB_CONTACT)
			index = 0;
		std::getline(std::cin, cmd, '\n');
		if (std::cin.eof())
			return (-1);
		for (int i = 0; i < (int)cmd.length(); i++)
			cmd[i] = toupper(cmd[i]);
		if (cmd == "ADD"){
			if (phone.ft_add_firstname(buff, index)
			|| phone.ft_add_lastname(buff, index)
			|| phone.ft_add_nickname(buff, index)
			|| phone.ft_add_numberphone(buff, index)
			|| phone.ft_add_darkest(buff, index))
				return (-1);
			index++;
		}
		else if (cmd == "SEARCH"){
			if (phone.ft_search())
				return (-1);
		}
		else if (cmd == "EXIT")
			ret = 1;
	}
	return (0);
}

int	main(void)
{
	PhoneBook phone;
	return (ft_while(phone));
}
