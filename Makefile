SRCDIR	:= ./srcs/
SRCS	:= ft_attacher.c \
		   ft_attacher2.c \
		   ft_attacher_prec.c \
		   ft_itoa_base_4b.c \
		   ft_itoa_base_8b.c \
		   ft_parser_char.c \
		   ft_parser_core.c \
		   ft_parser_manager.c \
		   ft_parser_num.c \
		   ft_parser_str.c \
		   ft_printf.c \
		   ft_putval.c \
		   ft_utils.c
SRCS	:= $(addprefix $(SRCDIR), $(SRCS))
OBJS	:= $(SRCS:.c=.o)
CC		:= cc
INCDIR	:= ./includes
NAME	:= libftprintf.a
CFLAGS	:= -Wall -Wextra -Werror
ARFLAGS	:= rc

.c.o:
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	mv ./libft/libft.a $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(MAKE) -C ./libft clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus
