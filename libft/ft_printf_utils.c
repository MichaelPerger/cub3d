/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoffman <shoffman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:24:55 by shoffman          #+#    #+#             */
/*   Updated: 2022/10/31 15:40:09 by shoffman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printnull(void)
{
	ft_printstr("(null)");
	return (6);
}

int	ft_printnbr(int n)
{
	int			sign;
	char		c;
	static int	chars_printed;

	sign = 1;
	chars_printed = 0;
	if (n < 0)
	{
		ft_printchar('-');
		sign = -1;
	}
	if (n / 10)
		ft_printnbr(n / 10 * sign);
	c = '0' + n % 10 * sign;
	chars_printed += ft_printchar(c);
	if (sign == -1)
		chars_printed++;
	return (chars_printed);
}

int	ft_printuns(unsigned int n)
{
	char		c;
	static int	chars_printed;

	chars_printed = 0;
	if (n / 10)
		ft_printuns(n / 10);
	c = '0' + n % 10;
	chars_printed += ft_printchar(c);
	return (chars_printed);
}

int	ft_printhex(unsigned long nbr, char *base)
{
	int	i;
	int	chars_printed;
	int	final_nbr[1000];

	i = 0;
	chars_printed = 0;
	if (nbr == 0)
	{
		chars_printed += ft_printchar('0');
		return (chars_printed);
	}
	while (nbr)
	{
		final_nbr[i] = nbr % 16;
		nbr = nbr / 16;
		i++;
	}
	while (--i >= 0)
		chars_printed += ft_printchar(base[final_nbr[i]]);
	return (chars_printed);
}
