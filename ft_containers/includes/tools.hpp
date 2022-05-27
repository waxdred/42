/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:17:07 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/26 20:10:30 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_HPP
# define TOOLS_HPP

# include <iostream>

namespace ft{
    	/*-------------------------------------------------------------*/
    	/*----------------------- enable_if ---------------------------*/

	/* @Brief Enable type if condition is met */  
	/* The type T is enabled as member type enable_if::type if Cond is true. */
	/* Otherwise, enable_if::type is not defined. */
	/* This is useful to hide signatures on compile time when a particular condition is not met, */ 
	/* since in this case, the member enable_if::type will not be defined and attempting to compile using it should fail. */
	/* It is defined with a behavior equivalent to: */
	template<bool Cond, class T = void>
	struct enable_if{
	};

	template<>
	struct enable_if<true> { typedef int type;
	};


    	/*-------------------------------------------------------------*/
    	/*-----------------------is_integral---------------------------*/
	template <typename T>
    	struct is_integral { static const bool value = false; };

    	template <>
    	struct is_integral<bool> { static const bool value = true; };
    	
	template <>
    	struct is_integral<char> { static const bool value = true; };

	template <>
	struct is_integral<short> { static const bool value = true; };

	template <>
	struct is_integral<int> { static const bool value = true; };

	template <>
	struct is_integral<long> { static const bool value = true; };

	template <>
	struct is_integral<long long> { static const bool value = true; };

	template <>
	struct is_integral<unsigned char> { static const bool value = true; };

	template <>
	struct is_integral<unsigned short> { static const bool value = true; };

	template <>
	struct is_integral<unsigned int> { static const bool value = true; };

	template <>
	struct is_integral<unsigned long> { static const bool value = true; };

	template <>
	struct is_integral<unsigned long long> { static const bool value = true; };


}//namespace
#endif
