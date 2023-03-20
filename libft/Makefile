# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mperger <mperger@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 08:18:10 by shoffman          #+#    #+#              #
#    Updated: 2023/03/01 16:36:31 by mperger          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= 	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
			ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
			ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
			ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
			ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_printf.c ft_printf_utils.c ft_strndup.c ft_split_improved.c \
			ft_strcmp.c \
			get_next_line.c get_next_line_utils.c

OBJS	= 	${SRCS:.c=.o}
RM		=	rm -f
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
NAME	=	libft.a

.c.o:
	${CC} -g ${CFLAGS} -c $< -o ${<:.c=.o} -I includes

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME} a.out
	
re: fclean all

test: ${NAME}
	${CC} ${CFLAGS} main.c ${NAME} -lbsd

.PHONY: all clean fclean re libft
