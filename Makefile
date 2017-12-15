CC=clang
CFLAGS=-Wall -Wextra -Werror -g -O3
ZADANIE=main fractol_handler fractol_draw fractol_plot_first fractol_init_first fractol_init_second fractol_plot_second fractol_inter
OBJ=$(addprefix obj/, $(addsuffix .o, $(ZADANIE)))
NAME=fractol

all: $(NAME)

$(NAME): $(OBJ) libft/libft.a
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) -pthread -lm -lmlx -lXext -lX11 libft/libft.a
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
	
