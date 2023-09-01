RM = rm -f

CC = gcc
FLAGS_MLX = -Lmlx -lmlx_Linux -Llibft -lft -lXext -lX11 -lm -lz
#FLAGS_MLX = -lmlx -framework OpenGL -framework AppKit
FLAGS = -Wall -Wextra -Werror

LIBFT= -L libft -lft

NAME = so_long
SRC = main.c map.c check_map.c player_position.c map_lengh.c exit_position.c set_up.c key_hook.c loop_hook.c check_items.c count_colectables.c

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(FLAGS) $(FLAGS_MLX) -c -o $@ $<

#%.o: %.c
#	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(OBJ) $(FLAGS) $(FLAGS_MLX) $(LIBFT) -o $(NAME)

clean:
	$(RM) $(OBJ)
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: bonus all clean fclean re
