/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 09:56:50 by jmilhas           #+#    #+#             */
/*   Updated: 2022/07/25 13:56:28 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

# include <iostream>

/**
	| ------------------------ TODO ------------------------------- *
	| ------------------------ FT::PAIR --------------------------- *
	|
    	| - Coplien form:
    	| [x](constructor):        Construct pair
    	| [x](destructor):         Destruct pair
    	| [x]operator=:            Assign pair
    	| [x]copy:            	   Copy pair
	|
	| - Non-member function overloads:
	| [x] operator ==
	| [x] operator !=
	| [x] operator <
	| [x] operator >
	| [x] operator <=
	| [x] operator >=
	|
	| - Makepair:
	| [x] make_pair
	| ------------------------------------------------------------- *
	*/
namespace ft{
	template<class U, class V>
	class pair{
		typedef U first_type;
		typedef V second_type;
		public:
			first_type	first;
			second_type	second;

			pair(): first(first_type()), second(second_type()){};

			pair (const first_type& a, const second_type& b): first(a), second(b){};

			template<class T1, class T2>
			pair(const pair<T1, T2> &p): first(p.first), second(p.second){};

			pair &operator=(const pair &pr){
				first = pr.first;
				second = pr.second;
				return (*this);
			}
	}; //pair

	template <class T1, class T2>
 	pair<T1,T2> make_pair (T1 x, T2 y){
		return ( pair<T1,T2>(x,y) );
	}
	
	template <class T1, class T2>
	bool operator==(const pair<T1, T2>&p1, const pair<T1, T2> &p2){
		return (p1.first == p2.first && p1.second == p2.second);
	}

	template <class T1, class T2>
	bool operator!=(const pair<T1, T2>&p1, const pair<T1, T2> &p2){
		return (p1.first != p2.first && p1.second != p2.second);
	}

	template <class T1, class T2>
	bool operator<(const pair<T1, T2>&p1, const pair<T1, T2> &p2){
		return (p1.first < p2.first || (!(p2.first < p1.first) && p1.second < p2.second));
	}

	template <class T1, class T2>
	bool operator<=(const pair<T1, T2>&p1, const pair<T1, T2> &p2){
		return (p1.first <= p2.first || (!(p2.first <= p1.first) && p1.second <= p2.second));
	}

	template <class T1, class T2>
	bool operator>(const pair<T1, T2>&p1, const pair<T1, T2> &p2){
		return (p1.first > p2.first || (!(p2.first > p1.first) && p1.second > p2.second));
	}

	template <class T1, class T2>
	bool operator>=(const pair<T1, T2>&p1, const pair<T1, T2> &p2){
		return (p1.first >= p2.first || (!(p2.first >= p1.first) && p1.second >= p2.second));
	}
}//namespace

#endif
