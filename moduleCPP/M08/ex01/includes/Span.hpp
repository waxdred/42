/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 09:33:23 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/01 15:08:01 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <exception>
# include <iostream>
# include <vector>
#include <initializer_list>

class	Span{
	private:	
		size_t	_n;
		std::vector<int>	_v;
	public:
		Span(void);
		Span(size_t n);
		Span(const Span &Span);
		~Span(void);

		void addNumber(int n);
		void addNumber(const std::initializer_list<int> &list);
		void addNumber(const std::vector<int> &v);
		long longestSpan(void);
		long shortestSpan(void);

		Span &operator = (const Span &span);
		class OutofRangeException : public std::exception{
			public:
				const char *what() const throw(){
					return ("Out of range!");
				}
		};
		class FullBufferException : public std::exception{
			public:
				const char *what() const throw(){
					return ("Buffer is full!");
				}
		};
		class CantSearchException : public std::exception{
			public:
				const char *what() const throw(){
					return ("Imposible span to short");
				}
		};
};
#endif
