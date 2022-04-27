/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:09:45 by jmilhas           #+#    #+#             */
/*   Updated: 2022/04/27 13:51:49 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include "Form.hpp"
# include <fstream>

class	ShrubberyCreationForm : public Form{
	private:	
		std::string _target;
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &shrubbery);
		~ShrubberyCreationForm(void);
		std::string	getTarget(void)const;
		void executeAction(void)const;
		ShrubberyCreationForm &operator = (const ShrubberyCreationForm &shrubbery);
};
#endif
