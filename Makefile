LIBDIR	:= lib
SRCDIR	:= srcs
OBJDIR	:= objs
FILES	:= ft_printf.c \
		   ft_parser.c \
		   ft_setter1.c \
		   ft_setter2.c \
		   ft_attacher1.c \
		   ft_attacher2.c \
		   ft_attacher_common.c \
		   ft_itoa_base_4bytes.c \
		   ft_itoa_base_8bytes.c
SRCS	:= $(addprefix $(SRCDIR)/, $(FILES))
OBJS	:= $(addprefix $(OBJDIR)/, $(FILES:.c=.o))
CC		:= cc
NAME	:= $(addprefix $(LIBDIR)/, libftprintf.a)
LIBFT	:= libft/lib/libft.a
INCDIR	:= includes
CFLAGS	:= -Wall -Wextra -Werror
ARFLAGS	:= rc

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(LIBFT):
	$(MAKE) -C libft

all: $(NAME)

clean:
	$(MAKE) -C libft clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(LIBFT)
	$(RM) $(NAME)

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus
