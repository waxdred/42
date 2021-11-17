/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 21:27:51 by jmilhas           #+#    #+#             */
/*   Updated: 2021/11/16 21:27:51 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h> 

int main(int argc, char **argv)
{
	int res;
	char str[] = "sal";
	char str1[] = "salfwfewfewfewfewfgrwgdsfdscvdsgvwdsgrwdsgrw";
	void *st = str;
	void *st1 = str1;


	res = ft_printf("%p\n", st);
	printf("%p\n", st);
	res = ft_printf("%p\n", st1);
	printf("%p\n", st1);
	return (0);
}
