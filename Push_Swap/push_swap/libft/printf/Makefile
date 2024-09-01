NAME = printf.a
CC = cc
CCFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_putchar.c ft_putstr.c ft_print_decimal.c ft_print_unsigned.c ft_print_hexa.c ft_print_pointer.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.SILENT: