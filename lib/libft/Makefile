NAME = libft.a

SRC = \
	ft_atoi.c \
	ft_calloc.c \
	ft_itoa.c \

OBJ = $(SRC:.c=.o)
LİBC = ar rc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)
$(NAME): $(OBJ)
	$(LİBC) $(NAME) $(OBJ)

clean: 
	$(RM) $(OBJ) $(BNSOBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re