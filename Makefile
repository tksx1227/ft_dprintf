SRCDIR	:= ./srcs/
SRCS	:= ft_attacher.c \
		   ft_attacher2.c \
		   ft_attacher_prec.c \
		   ft_itoa_base_4bytes.c \
		   ft_itoa_base_8bytes.c \
		   ft_parser.c \
		   ft_printf.c \
		   ft_putval.c \
		   ft_setter_core.c \
		   ft_setter_sub_char.c \
		   ft_setter_sub_num.c \
		   ft_setter_sub_str.c \
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
