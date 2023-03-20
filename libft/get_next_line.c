/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoffman <shoffman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:23:26 by shoffman          #+#    #+#             */
/*   Updated: 2022/11/02 08:56:17 by shoffman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_read_and_join(int fd, char *saved)
{
	char	*temp;
	int		bytes_read;

	temp = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr_line(saved, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(temp);
			return (saved);
		}
		temp[bytes_read] = '\0';
		saved = ft_strjoin_line(saved, temp);
	}
	free(temp);
	return (saved);
}

char	*ft_line_return(char *saved)
{
	int		len;
	int		i;
	char	*line;

	len = 0;
	if (!saved[len])
		return (NULL);
	while (saved[len] && saved[len] != '\n')
		len++;
	if (saved[len])
		len++;
	line = malloc(sizeof(char) * len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (saved[i] && i < len)
	{
		line[i] = saved[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_save_extra_chars(char *saved)
{
	int		len;
	char	*extra;
	int		i;

	len = 0;
	if (!saved[len])
	{
		free(saved);
		return (NULL);
	}
	while (saved[len] && saved[len] != '\n')
		len++;
	if (saved[len])
		len++;
	extra = malloc(sizeof(char) * (ft_strlen_line(saved) - len) + 1);
	i = 0;
	while (saved[len])
	{
		extra[i] = saved[len];
		i++;
		len++;
	}
	extra[i] = '\0';
	free(saved);
	return (extra);
}

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	saved = ft_read_and_join(fd, saved);
	if (!saved)
		return (NULL);
	line = ft_line_return(saved);
	saved = ft_save_extra_chars(saved);
	if (!line || *line == '\0')
	{
		free (line);
		free (saved);
		return (NULL);
	}
	return (line);
}
