LIBDIR	:= lib
SRCDIR	:= srcs
OBJDIR	:= objs
FILES	:= ft_dprintf.c ft_parser.c \
		   ft_setter1.c ft_setter2.c \
		   ft_attacher1.c ft_attacher2.c ft_attacher_common.c\
		   ft_itoa_base_4bytes.c ft_itoa_base_8bytes.c
SRCS	:= $(addprefix $(SRCDIR)/, $(FILES))
OBJS	:= $(addprefix $(OBJDIR)/, $(FILES:.c=.o))
DEPS	:= $(addprefix $(OBJDIR)/, $(FILES:.c=.d))
CC		:= cc
RM		:= rm -rf
NAME	:= $(LIBDIR)/libftdprintf.a
LIBFT	:= libft/lib/libft.a
INCDIR	:= libft/includes includes
CFLAGS	:= -Wall -Wextra -Werror -MMD -MP
ARFLAGS	:= rc

all: $(LIBDIR) $(OBJDIR) $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(addprefix -I, $(INCDIR)) -c $< -o $@

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

-include $(DEPS)

.PHONY: all clean fclean re
