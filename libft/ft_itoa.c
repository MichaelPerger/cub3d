/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoffman <shoffman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:13:32 by shoffman          #+#    #+#             */
/*   Updated: 2022/10/10 09:46:13 by shoffman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen(int n, int base)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
		i++;
	while (n)
	{
		n /= base;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	const char	*digits;
	int			i;

	digits = "0123456789";
	i = ft_numlen(n, 10);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	while (n)
	{
		if (n > 0)
			str[--i] = digits[n % 10];
		else
			str[--i] = digits[n % 10 * -1];
		n = n / 10;
	}
	return (str);
}

// #include <stdio.h>
// #include <limits.h>

// int main()
// {
//     int i = 156;
//     printf("%s", ft_itoa(i));
// }
