SRCDIR	= srcs
LIBDIR	= libft
INCDIR1	= includes
INCDIR2	= libft/includes
SRCS	= $(wildcard $(SRCDIR)/*.c) \
		  $(wildcard $(LIBDIR)/$(SRCDIR)/*.c)
OBJS	= $(SRCS:.c=.o)
CC		= cc
NAME	= libftprintf.a
CFLAGS	= -Wall -Wextra -Werror
ARFLAGS	= rc

.c.o:
	$(CC) $(CFLAGS) -I$(INCDIR1) -I$(INCDIR2) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
