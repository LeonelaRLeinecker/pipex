NAME	= pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_PATH = ../libft
LIBFT = $(LIBFT_PATH)/libft.a

SRCS	= main.c \
			child_process.c \
			parent_process.c \
			utils.c 

OBJS	= $(SRCS:.c=.o)

HEADER  = pipex.h

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re