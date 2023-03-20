/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_improved.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperger <mperger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:40:02 by mperger           #+#    #+#             */
/*   Updated: 2023/02/21 14:50:25 by mperger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_count(char const *s, char c, char t)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s && s[i])
	{
		if (s[i] != c && s[i] != t)
		{
			count++;
			while (s[i] && s[i] != c && s[i] != t)
				i++;
		}
		else
			i++;
	}
	return (count);
}

char	**ft_split_improved(char *s, char c, char t)
{
	char	**res;
	size_t	j;
	size_t	len;

	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (ft_word_count(s, c, t) + 1));
	if (!res)
		return (NULL);
	j = 0;
	while (s && *s)
	{
		if (*s != c && *s != t)
		{
			len = 0;
			while (s && s[len] && s[len] != c && s[len] != t)
				len++;
			res[j++] = ft_substr(s, 0, len);
			s += len;
		}
		else
			s++;
	}
	res[j] = NULL;
	return (res);
}
