
#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include <iomanip>

#define NB_CONTACT 8
class	Contact
{
	public:
		void		setFirstName(std::string &firstname);
		void		setLastName(std::string &lastname);
		void		setNickname(std::string &nickname);
		void		setNumberPhone(std::string &numberphone);
		void		setDarkest(std::string &darkest);
		std::string	getFirstName(void) const;
		std::string	getLastName(void) const;
		std::string	getNickname(void) const;
		std::string	getNumberPhone(void) const;
		std::string	getDarkest(void) const;
	private:
		std::string	_FirstName;
		std::string	_LastName;
		std::string	_Nickname;
		std::string	_NumberPhone;
		std::string	_Darkest;
};

void	ft_add_contact(Contact *C);
void	ft_add_darkest(Contact *C, std::string buff);
void	ft_add_firstname(Contact *C, std::string buff);
void	ft_add_lastname(Contact *C, std::string buff);
void	ft_add_nickname(Contact *C, std::string buff);
void	ft_add_numberphone(Contact *C, std::string buff);
void	ft_search(Contact *C);

#endif
