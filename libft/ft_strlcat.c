/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoffman <shoffman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:14:10 by shoffman          #+#    #+#             */
/*   Updated: 2022/10/11 13:14:34 by shoffman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dst_l;
	size_t	src_l;

	if (!dst && !size)
		return (0);
	dst_l = ft_strlen(dst);
	src_l = ft_strlen(src);
	i = 0;
	j = dst_l;
	if (dst_l < size - 1 && size > 0)
	{
		while (src[i] && dst_l + i < size - 1)
		{
			dst[j] = src[i];
			i++;
			j++;
		}
		dst[j] = '\0';
	}
	if (dst_l >= size)
		dst_l = size;
	return (dst_l + src_l);
}
