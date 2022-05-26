/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators_traits.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 12:01:07 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/26 13:02:16 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_TRAITS
# define ITERATORS_TRAITS

# include <iostream>

/**
* ------------------------ TODO ------------------------------- *
* ------------------------ FT_ITERATOR_TRAITS ----------------- *
* - Class:
*   [x] generic definition
*   [x] T* specialization
*   [x] const T* specialization
* ------------------------------------------------------------- *
*/

namespace ft{
	template <class Iterator> 
	class iterator_traits{
		public:
			typedef typename Iterator::difference_type	difference_type	;
			typedef typename Iterator::value_type		value_type;
			typedef typename Iterator::pointer		pointer;
			typedef typename Iterator::reference		reference;
			typedef typename Iterator::iterator_category	iterator_category;
	};//class iterators_traits
	
	template <class T> 
	class iterator_traits<T*>{
		public:
			typedef ptrdiff_t				difference_type;
			typedef T					value_type;
			typedef T					*pointer;
			typedef T					&reference;
			typedef std::random_access_iterator_tag		iterator_category;
	};//class iterators_traits
	
	template <class T> 
	class iterator_traits<const T*>{
		public:
			typedef ptrdiff_t				difference_type;
			typedef T					value_type;
			typedef const T					*pointer;
			typedef const T					&reference;
			typedef std::random_access_iterator_tag		iterator_category;

	};//class iterators_traits 

}//name space


#endif
