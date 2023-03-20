/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoffman <shoffman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:46:15 by shoffman          #+#    #+#             */
/*   Updated: 2022/10/31 15:40:20 by shoffman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printptr(unsigned long n)
{
	int	chars_printed;

	chars_printed = 0;
	if (!n)
	{
		chars_printed += ft_printstr("(nil)");
		return (chars_printed);
	}
	chars_printed += ft_printchar('0');
	chars_printed += ft_printchar('x');
	chars_printed += ft_printhex(n, HEX_LO);
	return (chars_printed);
}

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		i = ft_printnull();
		return (i);
	}
	while (str[i])
	{
		ft_printchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_check_format(va_list args, const char format_sp)
{
	int	chars_printed;

	chars_printed = 0;
	if (format_sp == 'c')
		chars_printed += ft_printchar(va_arg(args, int));
	if (format_sp == 's')
		chars_printed += ft_printstr(va_arg(args, char *));
	if (format_sp == 'p')
		chars_printed += ft_printptr(va_arg(args, unsigned long));
	if (format_sp == 'd' || format_sp == 'i')
		chars_printed += ft_printnbr(va_arg(args, int));
	if (format_sp == 'u')
		chars_printed += ft_printuns(va_arg(args, unsigned int));
	if (format_sp == 'x')
		chars_printed += ft_printhex(va_arg(args, unsigned int), HEX_LO);
	if (format_sp == 'X')
		chars_printed += ft_printhex(va_arg(args, unsigned int), HEX_UP);
	if (format_sp == '%')
		chars_printed += ft_printchar('%');
	return (chars_printed);
}

int	ft_printf(const char *text, ...)
{
	va_list	args;
	int		i;
	int		chars_printed;

	i = 0;
	chars_printed = 0;
	va_start(args, text);
	while (text[i])
	{
		if (text[i] == '%')
		{
			chars_printed += ft_check_format(args, text[i + 1]);
			i++;
		}
		else
			chars_printed += ft_printchar(text[i]);
		i++;
	}
	va_end(args);
	return (chars_printed);
}
