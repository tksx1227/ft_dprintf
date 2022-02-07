/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 10:30:03 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/08 00:55:09 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include "../libft/includes/libft.h"

# define INVALID_NUM -1

typedef struct s_printf
{
	int		width;
	int		prec;
	int		length;
	char	spec;
	char	*content;
	char	plus_sign;
	bool	is_zero;
	bool	is_number;
	bool	is_null_char;
	bool	sharp_flag;
	bool	left_align;
	bool	zero_flag;
}	t_printf;

typedef long long			t_ll;
typedef unsigned long long	t_ull;

int		ft_printf(const char *format, ...);

// Write functions
int		ft_put2per(char **s);
int		ft_putval(t_printf *info, int wc);

// Parser
bool	ft_parse(char **fmt, va_list *ap, t_printf *info);

// Setters
bool	ft_set_arg(va_list *ap, t_printf *info);
bool	ft_set_char(va_list *ap, t_printf *info);
bool	ft_set_per(t_printf *info);
bool	ft_set_hex_lower(va_list *ap, t_printf *info);
bool	ft_set_hex_upper(va_list *ap, t_printf *info);
bool	ft_set_str(va_list *ap, t_printf *info);
bool	ft_set_ptr(va_list *ap, t_printf *info);
bool	ft_set_digit(va_list *ap, t_printf *info);
bool	ft_set_int(va_list *ap, t_printf *info);
bool	ft_set_uint(va_list *ap, t_printf *info);

// Attacher of flags
bool	ft_attacher(t_printf *info);
bool	ft_attach_sharp_flag(t_printf *info);
bool	ft_attach_plus_sign(t_printf *info);
bool	ft_attach_zero_flag(t_printf *info);

// Attacher of precision
bool	ft_attach_prec(t_printf *info);
bool	ft_attach_prec_ptr(t_printf *info);
bool	ft_attach_prec_str(t_printf *info);
bool	ft_attach_prec_hex(t_printf *info);
bool	ft_attach_prec_num(t_printf *info);

// Attacher of width
bool	ft_attach_width(t_printf *info);

// Utils
int		get_digits(char **fmt);
int		add_write_count(int current, int new);
char	*add_prefix_with_free(char *s, char *prefix);
char	*add_suffix_with_free(char *s, char *suffix);
void	clear_info(t_printf *info, void (*del)(void *));
char	*ft_itoa_base_4bytes(int n, int base, bool is_unsigned);
char	*ft_itoa_base_8bytes(t_ll n, int base, bool is_unsigned);

#endif
