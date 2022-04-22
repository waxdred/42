/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:35:12 by jmilhas           #+#    #+#             */
/*   Updated: 2022/04/22 15:02:16 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

class	Form{
	private:	
		std::string const	_name;
		bool			_sign;
		int			_signGrade;
		int			_execGade;
	public:
		Form(std::string const name, int const signGrade, int const execGrade);
		Form(const Form &Form);
		~Form(void);
		std::string	getName(void)const;
		bool		getSign(void)const;
		int		getSignGrade(void)const;
		int		getExecGrade(void)const;
		class GradeTooHighException: public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException: public std::exception{
			public:
				virtual const char *what() const throw();
		};
		Form &operator = (const Form &form);
};
std::ostream &operator << (std::ostream &o, const Form s);
#endif
