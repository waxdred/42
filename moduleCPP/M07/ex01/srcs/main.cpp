/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 12:52:14 by jmilhas           #+#    #+#             */
/*   Updated: 2022/04/30 13:15:07 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
	int arr[] = {0, 1, 2, 3, 4};
	float farr[] = {4.2f, 42.0f, 0, .42f };
	std::string sarr[] = {"salut", "a", "toi"};

	std::cout << "Print value define" << std::endl;
        ::iter(arr, 5, printValue<int>);
	::iter(sarr, 3, printValue<std::string>);
	::iter(farr, 4, printValue<float>);

        ::iter(arr, 5, increment<int>);
        ::iter(farr, 4, increment<float>);
	std::cout << "Print value after increment" << std::endl;
        ::iter(arr, 5, printValue<int>);
	::iter(sarr, 3, printValue<std::string>);
	return 0;
}
