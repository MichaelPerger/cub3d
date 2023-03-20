/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperger <mperger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 08:58:09 by shoffman          #+#    #+#             */
/*   Updated: 2023/01/24 16:48:34 by mperger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

// #include <stdio.h>

// char const * string = "Hello proggen.org";

// int main( void )
// {
//   char const * pos = ft_strchr( string, 'p' );

//   if( pos ) printf( "%s: 'p' gefunden an Position: %d\n", string, pos
		//- string );
//   else      printf( "%s: kein 'p' gefunden\n", string );

//   pos = ft_strchr( string, 'x' );

//   if( pos ) printf( "%s: 'x' gefunden an Position: %d\n", string, pos
		//- string );
//   else      printf( "%s: kein 'x' gefunden\n", string );

//   return (EXIT_SUCCESS);
// }
