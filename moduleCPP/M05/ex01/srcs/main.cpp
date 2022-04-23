/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:20:14 by jmilhas           #+#    #+#             */
/*   Updated: 2022/04/22 14:29:16 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat b0("Michel", 1);

	try{
		Form form1("Form1", 1, 120);
		form1.beSigned(b0);
		b0.signForm(form1);
		std::cout << form1;

	}catch(const std::exception &e){
		std::cerr << e.what();
	}
	return 0;
}
