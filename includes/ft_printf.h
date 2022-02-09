/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 10:30:03 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/10 02:59:09 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include "../libft/includes/libft.h"

# define INVALID_NUM -1

typedef enum e_status
{
	FAIL = 0,
	SUCCESS = 1,
}	t_status;

typedef struct s_printf
{
	int		width;
	int		prec;
	int		length;
	char	spec;
	char	*content;
	char	sign;
	bool	is_zero;
	bool	is_number;
	bool	sharp_flag;
	bool	left_align;
	bool	zero_flag;
}	t_printf;

int			ft_printf(const char *format, ...);

// Write functions
int			ft_put2per(char **s);
int			ft_putval(t_printf *info, int wc);

// Parser
t_status	ft_parse(char **fmt, va_list *ap, t_printf *info);

// Setters
t_status	ft_set_arg(va_list *ap, t_printf *info);
t_status	ft_set_char(va_list *ap, t_printf *info);
t_status	ft_set_per(t_printf *info);
t_status	ft_set_hex(va_list *ap, t_printf *info);
t_status	ft_set_str(va_list *ap, t_printf *info);
t_status	ft_set_ptr(va_list *ap, t_printf *info);
t_status	ft_set_int(va_list *ap, t_printf *info);
t_status	ft_set_uint(va_list *ap, t_printf *info);

// Attacher
t_status	ft_attach(t_printf *info);
t_status	ft_attach_num(t_printf *info);
t_status	ft_attach_str(t_printf *info);
t_status	ft_attach_hex(t_printf *info);
t_status	ft_attach_ptr(t_printf *info);
t_status	ft_attach_prefix(t_printf *info, char *prefix);

// Utils
int			get_digits(char **fmt);
int			add_write_count(int current, int new);
void		ft_toupper_str(char *s);
void		clear_info(t_printf *info, void (*del)(void *));
char		*ft_itoa_base_4bytes(int n, int base, bool is_unsigned);
char		*ft_itoa_base_8bytes(long long n, int base, bool is_unsigned);

#endif
