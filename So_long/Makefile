NAME = so_long
CC = cc
CCFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -L ./minilibx-linux -lm -lmlx -Ilmlx -lXext -lX11

SRCS = src/so_long.c src/param_check.c src/map_utils.c src/init.c src/frees.c src/map_validations.c src/path_check.c src/init_display.c src/key_handler.c src/movements.c

LIBFT = ./libft/libft.a
PRINTF = ./libft/printf/printf.a


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	make -C libft
	cp libft/libft.a .
	mv libft.a ${NAME}
	make -C minilibx-linux
	ar rcs $(NAME) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) $(MLXFLAGS) -o $(NAME) 

clean:
	make clean -C ./libft
	rm -rf $(OBJS)

fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME)

update:
	@wget https://cdn.intra.42.fr/document/document/27195/minilibx-linux.tgz
	@tar -xzf minilibx-linux.tgz
	@rm minilibx-linux.tgz

re: fclean all

so:
		$(CC) -nostartfiles -fPIC $(CCFLAGS) $(SRCS)
		$(CC) -nostartfiles -shared -o libft.so $(OBJS)

$(LIBFT):
	cd libft && make

$(MINILIBX):
	cd minilibx-linux && make && ./configure

.SILENT: