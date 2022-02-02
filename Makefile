SRCDIR	= srcs
SRCS	= $(wildcard $(SRCDIR)/*.c)
OBJS	= $(SRCS:.c=.o)
CC		= cc
INCDIR	= ./includes
NAME	= libftprintf.a
CFLAGS	= -Wall -Wextra -Werror
ARFLAGS	= rc

.c.o:
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp ./libft/libft.a $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(MAKE) -C ./libft clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) ./libft/libft.a
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
