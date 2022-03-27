#include "../includes/Contact.hpp"

using namespace std;

void		Contact::setFirstName(string &firstname)
{
	this->_FirstName = firstname;
}

void		Contact::setLastName(string &lastname)
{
	this->_LastName = lastname;
}

void		Contact::setNickname(string &nickname)
{
	this->_Nickname = nickname;
}

void		Contact::setNumberPhone(string &numberphone)
{
	this->_NumberPhone = numberphone;
}

void		Contact::setDarkest(string &darkest)
{
	this->_Darkest = darkest;
}

string	Contact::getFirstName(void) const
{
	return (this->_FirstName);
}

string	Contact::getLastName(void) const
{
	return (this->_LastName);
}

string	Contact::getNickname(void) const
{
	return (this->_Nickname);
}

string	Contact::getNumberPhone(void) const
{
	return (this->_NumberPhone);
}

string	Contact::getDarkest(void) const
{
	return (this->_Darkest);
}

