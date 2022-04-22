/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:20:31 by jmilhas           #+#    #+#             */
/*   Updated: 2022/04/22 14:20:52 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class	Bureaucrat{
	private:	
		const std::string _name;
		int	_grade;
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string name);
		Bureaucrat(const int grade);
		Bureaucrat(const std::string name, const int grade);
		Bureaucrat(const Bureaucrat &Bureaucrat);
		~Bureaucrat(void);
		const std::string	getName(void)const;
		int			getGrade(void)const;
		Bureaucrat &operator = (const Bureaucrat &bureacrat);
		void	incrementeGrade(void);
		void	decrementeGrade(void);
		class GradeTooHightExeption: public std::exception{
			public:
				const char *what() const throw();
		};
		class GradeTooLowExeption: public std::exception{
			public:
				virtual const char *what() const throw();
		};
};
std::ostream &operator << (std::ostream &o, const Bureaucrat &s);
#endif
