NAME = push_swap

NAME_BONUS = checker

CC = cc

CFLAGS = -Wall -Werror -Wextra -I ./libft

SRCS =  Push_Swap.c\
		sorting.c\
		sortingb.c\
		sortingab.c\
		utility.c\
		toarray.c\
		sorts.c\
		finalsort.c\
		utility2.c\
		utility3.c

SRCS_BONUS =	utility.c\
				bonus/Push_Swap_Bonus.c\
				bonus/get_next_line.c\
				bonus/get_next_line_utils.c\
				bonus/sortingbonus.c\
				bonus/sortingbbonus.c\
				bonus/sortingabbonus.c

OBJ = $(SRCS:.c=.o)

OBJ_BONUS = $(SRCS_BONUS:.c=.o)
# .SILENT:
all: $(NAME)
	
$(NAME): $(OBJ)
	make -C ./libft
	gcc -g $(OBJ) ./libft/libft.a -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
	make -C ./libft
	gcc -g $(OBJ_BONUS) ./libft/libft.a -o $(NAME_BONUS)

clean:
	make clean -C ./libft
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re
