CC = cc 

CFLAGS= -Wall -Wextra -Werror 

RDFLAG = -lreadline

SRCS = minishell.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = mini_libft

LIBFT = $(LIBFT_DIR)/libft.a 

NAME = minishell

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(LIBFT) $(RDFLAG) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re mini_libft