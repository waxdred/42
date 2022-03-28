#include "../includes/Contact.hpp"

void	ft_add_firstname(Contact *C, std::string buff)
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

void	ft_add_lastname(Contact *C, std::string buff)
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

void	ft_add_nickname(Contact *C, std::string buff)
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

void	ft_add_numberphone(Contact *C, std::string buff)
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

void	ft_add_darkest(Contact *C, std::string buff)
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
