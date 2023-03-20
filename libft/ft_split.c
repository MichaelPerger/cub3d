/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoffman <shoffman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 09:53:32 by shoffman          #+#    #+#             */
/*   Updated: 2022/10/12 12:28:07 by shoffman         ###   ########.fr       */
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

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*substr;
// 	int		i;

// 	i = 0;
// 	if (!s)
// 		return (NULL);
// 	substr = (char *)malloc(sizeof(char) * len + 1);
// 	if (!substr)
// 		return (NULL);
// 	if (start >= ft_strlen(s))
// 	{
// 		substr[i] = '\0';
// 		return (substr);
// 	}
// 	i = 0;
// 	while (s[start] && len > 0)
// 	{
// 		substr[i++] = s[start++];
// 		len--;
// 	}
// 	substr[i] = '\0';
// 	return (substr);
// }

static size_t	ft_word_count(char const *s, char c)
{
	size_t	i;
	size_t	ret;

	i = 0;
	ret = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			ret++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	j;
	size_t	len;

	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!res)
		return (NULL);
	j = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				s++;
			res[j++] = ft_substr(s - len, 0, len);
		}
		else
			s++;
	}
	res[j] = 0;
	return (res);
}

// #include <stdio.h>

// int    main()
// {
//     int        index;
//     char    **split;

//     split = ft_split("      split       this for   me  !       ", ' ');
//     index = 0;
//     while (split[index])
//     {
//         printf("%s\n", split[index]);
//         index++;
//     }
// }
