NAME = libft.a

SRCS = ft_atoi.c ft_putnbr_fd.c ft_strdup.c ft_strlcpy.c ft_putstr_fd.c \
	ft_strlen.c ft_putchar_fd.c ft_split.c ft_strjoin.c ft_putendl_fd.c \
	ft_strlcat.c ft_strncmp.c ft_substr.c ft_memcpy.c ft_isspace.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

CC = gcc

RM = rm -f

AR = ar rcs

all: $(NAME)

$(NAME):$(OBJS)
	@$(AR) $(NAME) $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	$(RM) $(OBJS)

fclean:clean
	$(RM) $(NAME)

re: fclean all 

.PHONY: all clean fclean re
