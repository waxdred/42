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
# include "Bureaucrat.hpp"
class Bureaucrat;

class	Form{
	private:	
		std::string const	_name;
		bool			_sign;
		int			_signGrade;
		int			_execGrade;
	public:
		Form(std::string const name, int const signGrade, int const execGrade);
		Form(const Form &Form);
		~Form(void);
		std::string	getName(void)const;
		bool		getSign(void)const;
		int		getSignGrade(void)const;
		int		getExecGrade(void)const;
		void	beSigned(const Bureaucrat &b);
		Form &operator = (const Form &form);
		class GradeTooHightExeption: public std::exception{
			public:
				const char *what() const throw();
		};
		class GradeTooLowExeption: public std::exception{
			public:
				virtual const char *what() const throw();
		};
};
std::ostream &operator << (std::ostream &o, const Form &form);
#endif
