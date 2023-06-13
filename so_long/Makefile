RM = rm -f

CC = gcc
FLAGS = -Wall -Wextra -Werror

LIBFT= -L libft -lft

NAME = so_long
SRC =

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(OBJ) $(FLAGS) $(LIBFT) -o $(NAME)

clean:
	$(RM) $(OBJ)
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: bonus all clean fclean re
