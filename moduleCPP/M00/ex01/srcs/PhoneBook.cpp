/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 20:02:42 by jmilhas           #+#    #+#             */
/*   Updated: 2022/04/26 20:30:59 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

static bool	ft_check_entry(std::string &buff, int count)
{
	int	buf;

	if (!std::isdigit(buff[0]))
	{
		std::cout << "Error entry index:" << std::endl;
		return (false);
	}
	buf = stoi(buff);
	if (buf < 1 || buf > count)
	{
		std::cout << "Error index not found:" << std::endl;
		return (false);
	}
	return (true);
}

static void	ft_display_search(Contact *C, int index)
{
	std::cout << C[index].getFirstName() << ", " << C[index].getLastName() << ", ";
	std::cout << C[index].getNickname() << ", " << C[index].getNumberPhone() << ", ";
	std::cout << C[index].getDarkest() << std::endl;
}

static std::string	ft_format_char(std::string s)
{
	std::string	s1;

	s1 = s;
	if (s1.size() > 10)
	{
		s1[9] = '.';
		s1.resize(10);
	}
	return (s1);
}

static int ft_display_index(Contact *C)
{
	std::string	buff;
	int	ret;

	ret = 0;

	for (int i = 0; i < 8; i++)
	{
		buff = C[i].getFirstName();
		if (!buff.empty())
		{
			std::cout << "|" << std::setw(10) << std::right << i + 1;
			std::cout << "|" << std::setw(10) << std::right << ft_format_char(C[i].getFirstName());
			std::cout << "|" << std::setw(10) << ft_format_char(C[i].getLastName());
			std::cout << "|" << std::setw(10) << ft_format_char(C[i].getNickname()) << "|" << std::endl;
			ret++;
		}
	}
	return (ret);
}

void	PhoneBook::ft_search(Contact *C)
{
	std::string	buff;
	int	count;

	count = ft_display_index(C);
	if (!count)
	{
		std::cout << "No contact:" << std::endl;
		return;
	}
	std::cout << "Entry index of search:" << std::endl;
	getline(std::cin, buff, '\n');
	while (!ft_check_entry(buff, count))
	{
		count = ft_display_index(C);
		std::cout << "Entry index of search:" << std::endl;
		getline(std::cin, buff, '\n');
	}
	ft_display_search(C, stoi(buff) - 1);
}

void	PhoneBook::ft_add_firstname(Contact *C, std::string buff)
{
	std::cout << "First name:" << std::endl;
	getline(std::cin, buff, '\n');
	while (buff.empty())
	{
		std::cerr << "Error entry empty" << std::endl;
		std::cout << "First name:" << std::endl;
		getline(std::cin, buff, '\n');
	}
	C->setFirstName(buff);
}

void	PhoneBook::ft_add_lastname(Contact *C, std::string buff)
{
	std::cout << "Last name:" << std::endl;
	getline(std::cin, buff, '\n');
	while (buff.empty())
	{
		std::cerr << "Error entry empty" << std::endl;
		std::cout << "Last name:" << std::endl;
		getline(std::cin, buff, '\n');
	}
	C->setLastName(buff);
}

void	PhoneBook::ft_add_nickname(Contact *C, std::string buff)
{
	std::cout << "Nickname:" << std::endl;
	getline(std::cin, buff, '\n');
	while (buff.empty())
	{
		std::cerr << "Error entry empty" << std::endl;
		std::cout << "Nickname:" << std::endl;
		getline(std::cin, buff, '\n');
	}
	C->setNickname(buff);
}

void	PhoneBook::ft_add_numberphone(Contact *C, std::string buff)
{
	std::cout << "Number phone:" << std::endl;
	getline(std::cin, buff, '\n');
	while (buff.empty())
	{
		std::cerr << "Error entry empty" << std::endl;
		std::cout << "Number phone:" << std::endl;
		getline(std::cin, buff, '\n');
	}
	C->setNumberPhone(buff);
}

void	PhoneBook::ft_add_darkest(Contact *C, std::string buff)
{
	std::cout << "Darkest:" << std::endl;
	getline(std::cin, buff, '\n');
	while (buff.empty())
	{
		std::cerr << "Error entry empty" << std::endl;
		std::cout << "Darkest:" << std::endl;
		getline(std::cin, buff, '\n');
	}
	C->setDarkest(buff);
}

static  void	ft_menu(void)
{
	std::cout << "Available commands:" << std::endl;
	std::cout << "\tADD" << std::endl;
	std::cout << "\tSEARCH" << std::endl;
	std::cout << "\tEXIT" << std::endl;
	std::cout << std::endl;
	std::cout << "--> ";
}

int	PhoneBook::ft_add_contact(Contact *C)
{
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
			ft_add_firstname(&C[index], buff);
			ft_add_lastname(C, buff);
			ft_add_nickname(C, buff);
			ft_add_numberphone(C, buff);
			ft_add_darkest(C, buff);
		}
		else if (cmd == "SEARCH")
			ft_search(C);
		else if (cmd == "EXIT")
			ret = 1;
	}
	return (0);
}
