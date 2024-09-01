CC = cc
CCFLAGS = -Wall -Wextra -Werror

SERVER_NAME = server
CLIENT_NAME = client

SERVER_SRCS = server.c
CLIENT_SRCS =  client.c

SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

LIBFT = ./libft/libft.a

all: $(LIBFT) $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME): $(SERVER_OBJS)
		$(CC) $(CCFLAGS) -o $(SERVER_NAME) $(SERVER_OBJS) -L./libft -lft

$(CLIENT_NAME): $(CLIENT_OBJS)
		$(CC) $(CCFLAGS) -o $(CLIENT_NAME) $(CLIENT_OBJS) -L./libft -lft

$(LIBFT):
		${MAKE} -C ./libft

clean:
		${MAKE} clean -C ./libft
		rm -f $(SERVER_OBJS) $(CLIENT_OBJS)

fclean: clean
		${MAKE} fclean -C ./libft
		rm -f $(SERVER_NAME) $(CLIENT_NAME)

re: fclean all