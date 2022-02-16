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
NAME	:= libftprintf.a
LIBFT	:= libft/libft.a
INCDIR	:= includes
CFLAGS	:= -Wall -Wextra -Werror
ARFLAGS	:= rc

$(NAME): $(OBJS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(dir $(LIBFT))

all: $(NAME)

clean:
	$(MAKE) -C $(dir $(LIBFT)) clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(LIBFT)
	$(RM) $(NAME)

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus
