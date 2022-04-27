/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:35:52 by jmilhas           #+#    #+#             */
/*   Updated: 2022/04/27 13:51:16 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM
# define PRESIDENTIALPARDONFORM

# include <iostream>
# include "Form.hpp"

class	PresidentialPardonForm: public Form{
	private:	
		std::string _target;
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &PresidentialPardonForm);
		~PresidentialPardonForm(void);

		PresidentialPardonForm &operator = (const PresidentialPardonForm &president);
		std::string	getTarget(void)const;
		void executeAction(void) const;
};
#endif
