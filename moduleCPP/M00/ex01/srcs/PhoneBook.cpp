#include "Contact.hpp"

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

void	ft_search(Contact *C)
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

void	ft_add_contact(Contact *C)
{
	std::string	buff;

	ft_add_firstname(C, buff);
	ft_add_lastname(C, buff);
	ft_add_nickname(C, buff);
	ft_add_numberphone(C, buff);
	ft_add_darkest(C, buff);
}
