# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hvayon <hvayon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/22 23:13:38 by hvayon            #+#    #+#              #
#    Updated: 2022/02/18 21:44:21 by hvayon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER			= libft.h
NAMES			= ft_memset.c ft_bzero.c ft_memcpy.c\
					ft_memmove.c ft_memchr.c\
				  	ft_memcmp.c ft_isalpha.c\
				  	ft_isdigit.c ft_isalnum.c ft_isascii.c\
				  	ft_isprint.c ft_toupper.c ft_tolower.c\
				 	ft_strrchr.c ft_strncmp.c\
				   	ft_strlcat.c ft_strnstr.c\
				   	ft_atoi.c ft_calloc.c ft_strdup.c\
					ft_split.c\
					ft_itoa.c ft_strmapi.c ft_putchar_fd.c\
					ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c\
					ft_striteri.c\
					get_next_line.c get_next_line_utils.c\
					

OBJS			= $(NAMES:.c=.o)
D_FILES = $(patsubst %c,%d, $(NAMES))

CC				= cc
CFLAGS			= -Wall -Wextra -Werror
NAME			= libft.a

all:  $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $?

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -MD

include $(wildcard $(D_FILES))

clean:
	rm -f $(OBJS) $(BONUS_OBJS) $(D_FILES)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
