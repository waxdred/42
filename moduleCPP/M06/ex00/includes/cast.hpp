/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 10:07:20 by jmilhas           #+#    #+#             */
/*   Updated: 2022/04/29 18:31:22 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAST_HPP
# define CAST_HPP

# include <iostream>
# include <sstream>
# include <limits>
# include <iomanip>


enum type{
	T_CHAR,
	T_NUM,
	T_FLOAT,
	T_SPECIAL,
	T_SPECIAL_F,
	T_IMPOSSIBLE
};



class	Cast{
	private:	
		Cast(void);
		struct s_float{
			char	dot;
			long	num;
			long	num_dec;
			double	double_dec;
			std::string	f;
		};
		double	_value;
		type	_type;
		std::string _input;
		bool	checkInt(std::istringstream &iss);
		bool	checkDouble(std::istringstream &iss);
		bool	checkFloat(std::istringstream & iss);
		int8_t	checkSpecial(type *ret);
		void	printChar(void)const;
		void	printInt(void)const;
		void	printFloat(void)const;
		void	printDouble(void)const;
	public:
		Cast(const std::string &input);
		Cast(const Cast &Cast);
		~Cast(void);
		Cast &operator = (const Cast &conv);
		type	getType(void)const;
		type	getType(void);
		double	getValue(void)const;
		std::string	getInput(void)const;
		void	setValue(void);
		void	printConv(void)const;
};
std::ostream &operator << (std::ostream &o, const Cast s);
#endif
