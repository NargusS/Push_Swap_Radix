NAME =	push_swap
SRCS =	sort_small_stack.c\
		sort_big_stack.c\
		command.c\
		get_arg_init.c\
		push_swap.c\
		utils.c\
		utils2.c

OBJS := ${SRCS:.c=.o}

all: ${NAME}
	@printf "That's compile\n"
$(NAME): ${OBJS}
	@gcc -Wall -Werror -Wextra -o $(NAME) $(OBJS) -pthread -g
%.o: %.c
	$(CC) -Wall -Werror -Wextra -c $< -o $@
clean:
	@printf "Soft Cleaning\n"
	@rm -rf *.o

fclean: clean
	@printf "Hard clean"
	@rm -rf $(NAME)

re:	fclean all

PHONY: all bonus clean fclean re