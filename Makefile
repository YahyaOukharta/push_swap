CHECKER_NAME = checker
PUSH_SWAP_NAME = push_swap

LIBFT_PATH = libft/
LIBFT_NAME = $(LIBFT_PATH)libft.a

GNL_PATH = gnl/
GNL_SRCS = $(GNL_PATH)get_next_line.c $(GNL_PATH)get_next_line_utils.c -D BUFFER_SIZE=10
INCLUDES_PATH = includes/

UTILS_SRCS = srcs/utils/*.c

CHECKER_SRCS = srcs/checker/main.c $(UTILS_SRCS)
PUSH_SWAP_SRCS = srcs/push_swap/main.c $(UTILS_SRCS)



FLAGS = -fsanitize=address -g #-Wall -Werror -Wextra

all: $(CHECKER_NAME) $(PUSH_SWAP_NAME) 

$(CHECKER_NAME): $(LIBFT_NAME)
	gcc $(FLAGS) $(CHECKER_SRCS) $(GNL_SRCS) \
		-I $(INCLUDES_PATH) -I $(LIBFT_PATH) -I $(GNL_PATH) \
		-L $(LIBFT_PATH) -lft \
		-o $(CHECKER_NAME)

$(PUSH_SWAP_NAME): $(LIBFT_NAME)
	gcc $(FLAGS) $(PUSH_SWAP_SRCS) $(GNL_SRCS) \
		-I $(INCLUDES_PATH) -I $(LIBFT_PATH) -I $(GNL_PATH) \
		-L $(LIBFT_PATH) -lft \
		-o $(PUSH_SWAP_NAME)
		
$(LIBFT_NAME):
	make -C $(LIBFT_PATH)

clean:
	make -C $(LIBFT_PATH) clean

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(CHECKER_NAME) $(PUSH_SWAP_NAME) 

re: fclean all

c : re 
	./checker 1 2 3 4 5 6

ps : re 
	./push_swap 1 3 2 7 6 4 