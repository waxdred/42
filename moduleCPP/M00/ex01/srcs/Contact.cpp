#include "Contact.hpp"

void		Contact::setFirstName(std::string &firstname)
{
	this->_FirstName = firstname;
}

void		Contact::setLastName(std::string &lastname)
{
	this->_LastName = lastname;
}

void		Contact::setNickname(std::string &nickname)
{
	this->_Nickname = nickname;
}

void		Contact::setNumberPhone(std::string &numberphone)
{
	this->_NumberPhone = numberphone;
}

void		Contact::setDarkest(std::string &darkest)
{
	this->_Darkest = darkest;
}

std::string	Contact::getFirstName(void) const
{
	return (this->_FirstName);
}

std::string	Contact::getLastName(void) const
{
	return (this->_LastName);
}

std::string	Contact::getNickname(void) const
{
	return (this->_Nickname);
}

std::string	Contact::getNumberPhone(void) const
{
	return (this->_NumberPhone);
}

std::string	Contact::getDarkest(void) const
{
	return (this->_Darkest);
}

