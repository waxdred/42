/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:30:29 by jmilhas           #+#    #+#             */
/*   Updated: 2022/04/27 13:51:35 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "Form.hpp"
# include <iostream>
# include <ctime>

class	RobotomyRequestForm : public Form{
	private:	
		std::string _target;	
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &RobotomyRequestForm);
		~RobotomyRequestForm(void);
		RobotomyRequestForm &operator = (const RobotomyRequestForm &robot);
		std::string getTarget(void)const;
		void executeAction(void)const;
};
#endif
