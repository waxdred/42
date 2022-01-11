/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 20:49:51 by jmilhas           #+#    #+#             */
/*   Updated: 2021/11/16 20:49:51 by jmilhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_print_mem(int n)
{
	int	res;

	res = 0;
	res += ft_putstr("0x7ffe");
	res += ft_putnbr_unbase(n, BASE16, res);
	return (res);
}


int	ft_read_args(va_list *args, const char *str)
{
	int	res;

	res = 0;
	str++;
	if (!str)
		return res;
	else if(*str == 'c')
		res += ft_putchar(va_arg(*args, int));
	else if(*str == 's')
		res += ft_putstr(va_arg(*args, char *));
	else if(*str == 'p')
		res += ft_print_mem((unsigned int)va_arg(*args, int));
	else if(*str == 'i' || *str == 'd')
		res += ft_putnbr(va_arg(*args, int));
	else if(*str == 'u')
		res += ft_putnbr_unsigned(va_arg(*args, int));
	else if(*str == 'x')
		res += ft_putnbr_base(va_arg(*args, int), BASE16, res);
	else if (*str == '%')
		res += ft_putchar('%');
	str++;
	return (res);
}


int	ft_printf(const char *str, ...)
{
	int	res;
	va_list	args;
	
	if (!str)
		return (0);
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
			res = ft_read_args(&args, str++);
		else
			res += ft_putchar(*str);
		str++;
	}
	va_end(args);
	return (res);
}
