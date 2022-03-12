# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hvayon <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/19 17:48:41 by hvayon            #+#    #+#              #
#    Updated: 2022/02/19 17:49:03 by hvayon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRCS = drow_line.c drow.c drow_line_utils.c \
		key_deal.c main.c read_file.c \
		my_mlx_pixel_put.c \

SRCS_B = drow_line_bonus.c drow_bonus.c drow_line_utils_bonus.c \
				key_events_bonus.c main_bonus.c read_file_bonus.c \
				my_mlx_pixel_put_bonus.c \

SRCS_BONUS = $(SRCS_B)
OBJS = $(patsubst %.c, %.o, $(SRCS))
OBJS_BONUS = $(patsubst %.c, %.o, $(SRCS_BONUS))
CFLAGS = -Wall -Wextra -Werror
CC = gcc
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
LIB_NAME = libft/libft.a
LIB_SRC = ./libft/
HEADERS = fdf.h
HEADER_BONUS = fdf_bonus.h
HEADER_LIBFT = ./libft/libft.h
all : $(NAME)
$(NAME) : $(if $(findstring bonus, $(MAKECMDGOALS)),$(OBJS_BONUS), $(OBJS)) $(LIB_NAME)
	$(CC) $(CFLAGS) $(MLXFLAGS) $^ -o $(NAME)
%.o : %.c $(if $(findstring bonus, $(MAKECMDGOALS)), $(HEADER_BONUS), $(HEADERS)) $(HEADER_LIBFT)
	$(CC) $(CFLAGS) -c $< -o $@
$(LIB_NAME) : libft ;
bonus : $(NAME)
libft : 
	@make -C $(LIB_SRC)
clean :
	make clean -C libft
	rm -f $(OBJS) $(OBJS_BONUS)
fclean : clean
	make fclean -C libft
	rm -f $(NAME)
n:
	norminette $(SRCS_BONUS)
re: fclean all
.PHONY : all clean fclean re libft
