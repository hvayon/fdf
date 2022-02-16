# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hvayon <hvayon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/22 23:13:38 by hvayon            #+#    #+#              #
#    Updated: 2022/02/16 19:34:06 by hvayon           ###   ########.fr        #
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

CC				= cc
CFLAGS			= -Wall -Wextra -Werror
NAME			= libft.a


%.o: %.c ${HEADER}
	$(CC) $(CFLAGS) -c $< -o $@

all:  $(NAME)

$(NAME): $(OBJS) ${HEADER} Makefile
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re bonus
