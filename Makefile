NAME	= pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS	= main.c \
			child_process.c \
			parent_process.c \
			utils.c \
			copy_libft.c

OBJS	= $(SRCS:.c=.o)

HEADER  = pipex.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re