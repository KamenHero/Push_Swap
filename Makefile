NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS =  Push_Swap.c\
		sorting.c\
		sortingb.c\
		sortingab.c\
		utility.c\
		toarray.c\
		sorts.c\
		finalsort.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)
	
$(NAME): $(OBJ)
	make -C ./libft
	gcc $(OBJ) ./libft/libft.a -o $(NAME)

clean:
	make clean -C ./libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
