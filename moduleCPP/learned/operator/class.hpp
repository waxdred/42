/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 17:49:17 by jmilhas           #+#    #+#             */
/*   Updated: 2022/04/30 18:31:09 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_HPP
# define CLASS_HPP

#include <exception>
# include <iostream>

class	Perso{
	private:	
		std::string 	_name;
		int		_ages;
		bool		_gender;
		Perso(void);
	public:
		//constructor
		Perso(const std::string &names, int ages, bool gender);
		Perso(const Perso &perso);
		//detructor
		~Perso(void);

		//getter;
		std::string	getName(void)const;
		int		getAges(void)const;
		bool		getgender(void)const;
		//setter;
		//operator
		Perso &operator = (const Perso &perso);
		void operator + (Perso &perso);

		//try catch
		class errorYouToOld : public std::exception{
			const char *what() const throw();
		};
};
//operator
std::ostream &operator<<(std::ostream &o, const Perso &p);
#endif
