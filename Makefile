NAME = libftprintf.a

CC = cc

CFLAGS = -Werror -Wall -Wextra

SRCS = $(wildcard *.c)

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
		ar -rcs $(NAME) $(OBJS)

.PHONY: all clean fclean re

all: $(NAME)

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all