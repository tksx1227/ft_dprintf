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
RM		:= rm -rf
NAME	:= $(addprefix $(LIBDIR)/, libftprintf.a)
LIBFT	:= libft/lib/libft.a
INCDIR	:= includes
CFLAGS	:= -Wall -Wextra -Werror
ARFLAGS	:= rc

all: $(LIBDIR) $(OBJDIR) $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(LIBFT):
	$(MAKE) -C libft

$(LIBDIR):
	mkdir -p $@

$(OBJDIR):
	mkdir -p $@

clean:
	$(MAKE) -C libft clean
	$(RM) $(OBJDIR)

fclean: clean
	$(MAKE) -C libft fclean
	$(RM) $(LIBDIR)

re: fclean all

.PHONY: all clean fclean re
