CC=clang
CFLAGS=-Wall -Wextra -Werror -g
ZADANIE=main fractol_handler fractol_draw
OBJ=$(addprefix obj/, $(addsuffix .o, $(ZADANIE)))
NAME=fractol

all: $(NAME)

$(NAME): $(OBJ) libft/libft.a
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) -lm -lmlx -framework OpenGL -framework AppKit libft/libft.a
libft/libft.a:
	make -C libft/
obj/%.o: %.c
	$(CC) -c $^ -o $@ $(CFLAGS)
clean:
	rm -f $(OBJ)
	make -C libft/ clean
fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean
re: fclean all
	
