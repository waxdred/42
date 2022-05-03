/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 22:23:04 by jmilhas           #+#    #+#             */
/*   Updated: 2022/04/29 23:10:28 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Info.hpp"

int main(void)
{
	Base *gen;

	gen = generate();
	identify(gen);
	identify(*gen);
	delete gen;
	return 0;
}
