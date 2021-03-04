CHECKER_NAME = checker
PUSH_SWAP_NAME = push_swap

LIBFT_PATH = libft/
LIBFT_NAME = $(LIBFT_PATH)libft.a

INCLUDES_PATH = includes/

CHECKER_SRCS = srcs/checker/main.c
PUSH_SWAP_SRCS = srcs/push_swap/main.c

all: $(CHECKER_NAME) $(PUSH_SWAP_NAME) 

$(CHECKER_NAME): $(LIBFT_NAME)
	gcc $(CHECKER_SRCS) -I $(INCLUDES_PATH) -L $(LIBFT_PATH) -lft -o $(CHECKER_NAME)

$(PUSH_SWAP_NAME): $(LIBFT_NAME)
	gcc $(PUSH_SWAP_SRCS) -I $(INCLUDES_PATH) -L $(LIBFT_PATH) -lft -o $(PUSH_SWAP_NAME)

$(LIBFT_NAME):
	make -C $(LIBFT_PATH)

clean:
	make -C $(LIBFT_PATH) clean

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(CHECKER_NAME) $(PUSH_SWAP_NAME) 

re: fclean all