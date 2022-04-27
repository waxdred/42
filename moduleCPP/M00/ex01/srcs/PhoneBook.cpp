/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 20:02:42 by jmilhas           #+#    #+#             */
/*   Updated: 2022/04/28 00:41:59 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iomanip>

PhoneBook::PhoneBook(void){
	std::string t = "";
	for (int i = 0; i < NB_CONTACT; i++){
		this->_contact[i].setFirstName(t);
	}
}

PhoneBook::~PhoneBook(void){
	return;
}
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

void	ft_display_search(Contact &C)
{
	std::cout << C.getFirstName() << ", " << C.getLastName() << ", ";
	std::cout << C.getNickname() << ", " << C.getNumberPhone() << ", ";
	std::cout << C.getDarkest() << std::endl;
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

int	PhoneBook::ft_display_index(void)
{
	std::string	buff;
	int	ret;

	ret = 0;

	for (int i = 0; i < 8; i++)
	{
		buff = this->_contact[i].getFirstName();
		if (!buff.empty())
		{
			std::cout << "|" << std::setw(10) << std::right << i + 1;
			std::cout << "|" << std::setw(10) << std::right << ft_format_char(this->_contact[i].getFirstName());
			std::cout << "|" << std::setw(10) << ft_format_char(this->_contact[i].getLastName());
			std::cout << "|" << std::setw(10) << ft_format_char(this->_contact[i].getNickname()) << "|" << std::endl;
			ret++;
		}
	}
	return (ret);
}

int	PhoneBook::ft_search(void)
{
	std::string	buff;
	int	count;

	count = ft_display_index();
	if (!count)
	{
		std::cout << "No contact:" << std::endl;
		return (0);
	}
	std::cout << "Entry index of search:" << std::endl;
	getline(std::cin, buff, '\n');
	if (std::cin.eof())
		return (-1);
	while (!ft_check_entry(buff, count))
	{
		count = ft_display_index();
		std::cout << "Entry index of search:" << std::endl;
		getline(std::cin, buff, '\n');
		if (std::cin.eof())
			return (-1);
	}
	ft_display_search(this->_contact[stoi(buff) - 1]);
	return (0);
}

int	PhoneBook::ft_add_firstname(std::string buff, const int index)
{
	std::cout << "First name:" << std::endl;
	getline(std::cin, buff, '\n');
	if (std::cin.eof())
		return (-1);
	while (buff.empty())
	{
		std::cerr << "Error entry empty" << std::endl;
		std::cout << "First name:" << std::endl;
		getline(std::cin, buff, '\n');
		if (std::cin.eof())
			return (-1);
	}
	this->_contact[index].setFirstName(buff);
	return (0);
}

int	PhoneBook::ft_add_lastname(std::string buff, const int index)
{
	std::cout << "Last name:" << std::endl;
	getline(std::cin, buff, '\n');
	if (std::cin.eof())
		return (-1);
	while (buff.empty())
	{
		std::cerr << "Error entry empty" << std::endl;
		std::cout << "Last name:" << std::endl;
		getline(std::cin, buff, '\n');
		if (std::cin.eof())
			return (-1);
	}
	this->_contact[index].setLastName(buff);
	return (0);
}

int	PhoneBook::ft_add_nickname(std::string buff, const int index)
{
	std::cout << "Nickname:" << std::endl;
	getline(std::cin, buff, '\n');
	if (std::cin.eof())
		return (-1);
	while (buff.empty())
	{
		std::cerr << "Error entry empty" << std::endl;
		std::cout << "Nickname:" << std::endl;
		getline(std::cin, buff, '\n');
		if (std::cin.eof())
			return (-1);
	}
	this->_contact[index].setNickname(buff);
	return (0);
}

int	PhoneBook::ft_add_numberphone(std::string buff, const int index)
{
	std::cout << "Number phone:" << std::endl;
	getline(std::cin, buff, '\n');
	while (buff.empty())
	{
		std::cerr << "Error entry empty" << std::endl;
		std::cout << "Number phone:" << std::endl;
		getline(std::cin, buff, '\n');
		if (std::cin.eof())
			return (-1);
	}
	this->_contact[index].setNumberPhone(buff);
	return (0);
}

int	PhoneBook::ft_add_darkest(std::string buff, const int index)
{
	std::cout << "Darkest:" << std::endl;
	getline(std::cin, buff, '\n');
	if (std::cin.eof())
		return (-1);
	while (buff.empty())
	{
		std::cerr << "Error entry empty" << std::endl;
		std::cout << "Darkest:" << std::endl;
		getline(std::cin, buff, '\n');
		if (std::cin.eof())
			return (-1);
	}
	this->_contact[index].setDarkest(buff);
	return (0);
}
