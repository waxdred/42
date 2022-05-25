/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 08:02:32 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/25 09:21:40 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_HPP
# define ALGORITHM_HPP

# include <iostream>
/**
	* ------------------------ TODO ------------------------------- *
	* ------------------------ ALGORITHM -------------------------- *
	*
	* - Equal:
	* [ ]equality:
	* [ ]predicate:
	*
	* -lexicographical_compare
	*  [ ]default:
	*  [ ]custom:
	*
	* ------------------------------------------------------------- *
	*/

namespace ft{

	/* ------------------------------------------------------------- */
	/* ------------------------ EQUAL ------------------------------ */
	template <class InputIterator1, class InputIterator2>
  	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2){
		while (first1 != last1){
			if (!(*first1 == *first2))
				return (false);
			first1++;
			first2++;
		}
		return (true);
	}

	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
  	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred){
		while (first1 != last1){
			if (!pred(*first1,*first2))
				return (false);
			first1++;
			first2++;
		}
		return (true);

	}
	/* ------------------------------------------------------------- */
	/* ------------------------ EQUAL ------------------------------ */
	template <class InputIterator1, class InputIterator2>
  	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2){
		while (first1 != last1)
  		{
    			if (first2 == last2 || *first2 < *first1)
				return false;
    			else if (*first1 < *first2) 
				return true;
    			++first1; 
			++first2;
  		}
  			return (first2!=last2);
	}

	template <class InputIterator1, class InputIterator2, class Compare>
  	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                        InputIterator2 first2, InputIterator2 last2, Compare comp){
		while (first1 != last1)
  		{
    			if (first2 == last2 || comp(*first2, *first1))
				return false;
    			else if (comp(*first1, *first2)) 
				return true;
    			++first1; 
			++first2;
  		}
  			return (first2!=last2);

	}


}//namespace
	
#endif
