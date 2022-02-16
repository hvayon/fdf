HEADER = fdf.h
HEADER_BONUS = fdf_bonus.h
NAME = fdf
SRC = 	drow_line.c drow.c drow_line_utils.c \
		key_deal.c main.c read_file.c \
		my_mlx_pixel_put.c \

SRC_BONUS = 	drow_line_bonus.c drow_bonus.c drow_line_utils_bonus.c \
				key_events_bonus.c main_bonus.c read_file_bonus.c \
				my_mlx_pixel_put_bonus.c \

CC = cc 
FLAGS = -Wall -Wextra -Werror

DIR_LIB = libft
LIB = $(DIR_LIB)/libft.a

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

lib: 
	@make -C libft

$(NAME) : lib $(OBJ) $(LIB) 
	@$(CC) $(FLAGS) $(OBJ) $(LIB) -o $(NAME) -lmlx -framework OpenGL -framework AppKit

%.o: %.c $(HEADER) 
	$(CC) $(FLAGS) -c $< -o $@

bonus: lib $(OBJ_BONUS) $(HEADER_BONUS)
	$(CC) $(FLAGS) $(OBJ_BONUS) $(LIB) -o $(NAME) -lmlx -framework OpenGL -framework AppKit

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
	make -C $(DIR_LIB) clean

fclean: clean
	rm -f $(NAME)
	make -C $(DIR_LIB) fclean

re:	fclean all

.PHONY: all clean fclean re bonus
