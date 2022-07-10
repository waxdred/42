/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:05:20 by jmilhas           #+#    #+#             */
/*   Updated: 2022/07/07 17:06:15 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_HPP
#define TYPE_HPP

namespace ft
{
	template <bool isConst, typename isFalse, typename isTrue>
	struct chooseConst {};
	
	template <typename isFalse, typename isTrue>
	struct chooseConst<false, isFalse, isTrue>
	{
	    typedef isFalse type;
	};
	
	template <typename isFalse, typename isTrue>
	struct chooseConst<true, isFalse, isTrue>
	{
	    typedef isTrue type;
	};
	
} //namespace ft

#endif
