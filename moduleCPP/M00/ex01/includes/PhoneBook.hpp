/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 20:02:29 by jmilhas           #+#    #+#             */
/*   Updated: 2022/04/28 00:34:44 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"

#define NB_CONTACT 8
class	PhoneBook{
	private:
		Contact _contact[NB_CONTACT];
	public:
		PhoneBook(void);
		~PhoneBook(void);
		int	ft_search(void);
		int	ft_add_darkest(std::string buff, const int index);
		int	ft_add_firstname(std::string buff, const int index);
		int	ft_add_lastname(std::string buff, const int index);
		int	ft_add_nickname(std::string buff, const int index);
		int	ft_add_numberphone(std::string buff, const int index);
		int 	ft_display_index(void);
};
#endif
