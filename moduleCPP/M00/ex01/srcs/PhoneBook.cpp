#include "../includes/Contact.hpp"
#include <cstdlib>
#include <string>

using namespace std;

static bool	ft_check_entry(string &buff, int count)
{
	int	buf;

	if (!std::isdigit(buff[0]))
	{
		cout << "Error entry index:" << endl;
		return (false);
	}
	buf = stoi(buff);
	if (buf < 0 || buf >= count)
	{
		cout << "Error index not found:" << endl;
		return (false);
	}
	return (true);
}

static void	ft_display_search(Contact *C, int index)
{
	cout << C[index].getFirstName() << ", " << C[index].getLastName() << ", ";
	cout << C[index].getNickname() << ", " << C[index].getNumberPhone() << ", ";
	cout << C[index].getDarkest() << endl;
}

static string	ft_format_char(string s)
{
	string	s1;

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
	string	buff;
	int	ret;

	ret = 0;

	for (int i = 0; i < 8; i++)
	{
		buff = C[i].getFirstName();
		if (!buff.empty())
		{
			cout << "|" << setw(10) << right << i;
			cout << "|" << setw(10) << right << ft_format_char(C[i].getFirstName());
			cout << "|" << setw(10) << ft_format_char(C[i].getLastName());
			cout << "|" << setw(10) << ft_format_char(C[i].getNickname()) << "|" << endl;
			ret++;
		}
	}
	return (ret);
}

void	ft_search(Contact *C)
{
	string	buff;
	int	count;

	count = ft_display_index(C);
	if (!count)
	{
		cout << "No contact:" << endl;
		return;
	}
	cout << "Entry index of search:" << endl;
	getline(cin, buff, '\n');
	while (!ft_check_entry(buff, count))
	{
		count = ft_display_index(C);
		cout << "Entry index of search:" << endl;
		getline(cin, buff, '\n');
	}
	ft_display_search(C, stoi(buff));
}

void	ft_add_contact(Contact *C)
{
	string	buff;

	ft_add_firstname(C, buff);
	ft_add_lastname(C, buff);
	ft_add_nickname(C, buff);
	ft_add_numberphone(C, buff);
	ft_add_darkest(C, buff);
}
