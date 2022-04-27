/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 20:02:29 by jmilhas           #+#    #+#             */
/*   Updated: 2022/04/26 20:27:45 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"

class	PhoneBook{
	public:
		PhoneBook(void);
		~PhoneBook(void);
		static int	ft_add_contact(Contact *C);
		static void	ft_search(Contact *C);
		static void	ft_add_darkest(Contact *C, std::string buff);
		static void	ft_add_firstname(Contact *C, std::string buff);
		static void	ft_add_lastname(Contact *C, std::string buff);
		static void	ft_add_nickname(Contact *C, std::string buff);
		static void	ft_add_numberphone(Contact *C, std::string buff);
};
#endif
