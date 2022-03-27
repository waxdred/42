#include "../includes/Contact.hpp"

using namespace std;

void	ft_add_firstname(Contact *C, string buff)
{
	cout << "First name:" << endl;
	getline(cin, buff, '\n');
	while (buff.empty())
	{
		cerr << "Error entry empty" << endl;
		cout << "First name:" << endl;
		getline(cin, buff, '\n');
	}
	C->setFirstName(buff);
}

void	ft_add_lastname(Contact *C, string buff)
{
	cout << "Last name:" << endl;
	getline(cin, buff, '\n');
	while (buff.empty())
	{
		cerr << "Error entry empty" << endl;
		cout << "Last name:" << endl;
		getline(cin, buff, '\n');
	}
	C->setLastName(buff);
}

void	ft_add_nickname(Contact *C, string buff)
{
	cout << "Nickname:" << endl;
	getline(cin, buff, '\n');
	while (buff.empty())
	{
		cerr << "Error entry empty" << endl;
		cout << "Nickname:" << endl;
		getline(cin, buff, '\n');
	}
	C->setNickname(buff);
}

void	ft_add_numberphone(Contact *C, string buff)
{
	cout << "Number phone:" << endl;
	getline(cin, buff, '\n');
	while (buff.empty())
	{
		cerr << "Error entry empty" << endl;
		cout << "Number phone:" << endl;
		getline(cin, buff, '\n');
	}
	C->setNumberPhone(buff);
}

void	ft_add_darkest(Contact *C, string buff)
{
	cout << "Darkest:" << endl;
	getline(cin, buff, '\n');
	while (buff.empty())
	{
		cerr << "Error entry empty" << endl;
		cout << "Darkest:" << endl;
		getline(cin, buff, '\n');
	}
	C->setDarkest(buff);
}
