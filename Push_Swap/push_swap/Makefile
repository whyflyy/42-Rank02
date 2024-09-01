NAME = push_swap
CC = cc
CCFLAGS = -Wall -Wextra -Werror -g

SRCS = push_swap.c split.c handle_errors.c init_stack.c ready_a.c ready_b.c sort.c stack_utils.c rotate.c reverse_rotate.c sort_three.c push.c swap.c 

LIBFT = ./libft/libft.a
PRINTF = ./libft/printf/printf.a


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	cp libft/libft.a .
	mv libft.a ${NAME}
	ar rcs $(NAME) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

clean:
	make clean -C ./libft
	rm -rf $(OBJS)

fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME)

re: fclean all

so:
		$(CC) -nostartfiles -fPIC $(CCFLAGS) $(SRCS)
		$(CC) -nostartfiles -shared -o libft.so $(OBJS)

$(LIBFT):
	cd libft && make 
$(PRINTF):
	cd printf && make 

.SILENT: