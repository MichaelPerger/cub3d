/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperger <mperger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:02:29 by shoffman          #+#    #+#             */
/*   Updated: 2022/12/20 16:48:49 by mperger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	little_len;

	i = 0;
	j = 0;
	if (!big && !len)
		return (NULL);
	little_len = ft_strlen(little);
	if (!little[j])
		return ((char *)big);
	while (big[i] && i < len)
	{
		while (big[i + j] == little[j] && i + j < len)
		{
			j++;
			if (j == little_len && !little[j])
				return ((char *)(&big[i]));
		}
		i++;
		j = 0;
	}
	return (NULL);
}

// #include <stdio.h>

// int main()
// {
//     char big[30] = "aaabcabcd";
//     char little[10] = "a";

//     printf("%s", ft_strnstr(big, little, 1));
// }
