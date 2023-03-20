/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperger <mperger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:09:51 by shoffman          #+#    #+#             */
/*   Updated: 2023/03/01 16:31:36 by mperger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

//libft
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strndup(const char *s, size_t n);
char	**ft_split_improved(char *s, char c, char t);
int		ft_strcmp(const char *s1, const char *s2);

//ft_printf
# ifndef HEX_UP
#  define HEX_UP "0123456789ABCDEF"
# endif

# ifndef HEX_LO
#  define HEX_LO "0123456789abcdef"
# endif

int		ft_printf(const char *text, ...);
int		ft_check_format(va_list args, const char format_sp);
int		ft_printstr(char *str);
int		ft_printptr(unsigned long n);
int		ft_printchar(char c);
int		ft_printhex(unsigned long nbr, char *base);
int		ft_printuns(unsigned int n);
int		ft_printnbr(int n);
int		ft_printnull(void);

//get_next_line
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

char	*ft_read_and_join(int fd, char *saved);
char	*ft_line_return(char *saved);
char	*ft_save_extra_chars(char *saved);
char	*get_next_line(int fd);
char	*ft_strjoin_line(char *s1, char *s2);
int		ft_strchr_line(const char *s, int c);
size_t	ft_strlen_line(const char *str);

#endif
