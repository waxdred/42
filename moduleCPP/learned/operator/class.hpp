/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 17:49:17 by jmilhas           #+#    #+#             */
/*   Updated: 2022/04/30 17:51:10 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_HPP
# define CLASS_HPP

# include <iostream>

class	perso{
	private:	
		std::string 	_name;
		int		ages;
		bool		gender;
	public:
		perso(void);
		perso(const perso &perso);
		~perso(void);

		perso &operator = (const perso &perso);
};
#endif
