SERVER= server
CLIENT= client
SERVER_BNS= server_bns
CLIENT_BNS= client_bns
LIBFT = Libft/libft.a

NAME= all

CC= gcc

CFLAGS= -Wall -Wextra -Werror -I$(LIBFT)

RM= rm -rf

all: $(SERVER) $(CLIENT)

$(SERVER): $(LIBFT)
	$(CC) $(CFLAGS) server.c -o $(SERVER)

$(CLIENT): $(LIBFT)
	$(CC) $(CFLAGS) client.c -o $(CLIENT)

$(SERVER_BNS): $(LIBFT)
	$(CC) $(CFLAGS) server.c -o $(SERVER_BNS)

$(CLIENT_BNS): $(LIBFT)
	$(CC) $(CFLAGS) client.c -o $(CLIENT_BNS)

$(LIBFT):
	make -s -C Libft

bonus: $(SERVER_BNS) $(CLIENT_BNS)

clean:
	$(RM) $(SERVER) $(CLIENT) $(SERVER_BNS) $(CLIENT_BNS)
	make -s -C Libft clean

fclean: clean
	make -s -C Libft fclean

re: fclean all

.PHONY: all clean fclean re bonus
