/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 09:33:23 by jmilhas           #+#    #+#             */
/*   Updated: 2022/05/18 10:27:32 by jmilhas          ###   ########.fr       */
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
		long longestSpan(void);
		long shortestSpan(void);
		unsigned int	size() const;

		template<class It>
		void	addNumber(It begin, It end)
		{
			if ((end - begin) + this->_v.size() <= this->_n)
			{
				std::copy(begin, end, std::back_inserter(this->_v));
				std::sort(this->_v.begin(), this->_v.end());
				return ;
			}
			else if (this->_v.size() <= this->_n)
			{
				std::copy(begin, begin + (this->_n - this->_v.size()), std::back_inserter(this->_v));
				std::sort(this->_v.begin(), this->_v.end()); 
			}
			throw OutofRangeException();
		};
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
