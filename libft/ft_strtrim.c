/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoffman <shoffman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:38:58 by shoffman          #+#    #+#             */
/*   Updated: 2022/10/10 11:01:56 by shoffman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_contains_set(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	char	*str;
	int		len;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	start = 0;
	while (start < len && ft_contains_set(s1[start], set))
		start++;
	len--;
	while (len > start && ft_contains_set(s1[len], set))
		len--;
	str = (char *)malloc(sizeof(char) * (++len - start) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len - start)
	{
		str[i] = s1[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

// #include <stdio.h>

// int main()
// {
//     char str[] = "";
//     char set[] = " \n\t";
//     char *result;

//     result = ft_strtrim(str, set);
//     printf("%s", result);
// }
