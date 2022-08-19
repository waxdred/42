/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <jmilhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 09:32:25 by jmilhas           #+#    #+#             */
/*   Updated: 2022/08/18 09:52:16 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/connect.hpp"

#include <exception>
#include <iostream>
#include <string>
#include <vector>
int main(int ac, char **av){
	if (ac != 3){
		std::cerr << "Error: <Port> <Password>" << std::endl; 
	}
	std::string port = av[1];
	std::string pwd = av[2];
	try{
		irc::Connect irc(port, pwd);
		irc.ft_run();
	}
	catch(irc::Connect::ErrorTCP &e){
		std::cerr << e.what()<< std::endl;
	}
	
}
