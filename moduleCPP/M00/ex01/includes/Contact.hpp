/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 20:02:48 by jmilhas           #+#    #+#             */
/*   Updated: 2022/04/26 20:06:35 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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


#endif
