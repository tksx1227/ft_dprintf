/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 10:30:03 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/02 01:12:42 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include "../libft/includes/libft.h"

typedef struct s_print
{
	int		wc;
	int		width;
	char	spec;
	char	*content;
	bool	sharp_flag;
	bool	space_flag;
	bool	plus_flag;
	bool	minus_flag;
	bool	zero_flag;
	bool	dot_flag;
}	t_print;

int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_printf(const char *format, ...);
char	*ft_itoa_base(long long n, int base, bool islower);

// Main Parsers
bool	ft_parser(char **fmt, va_list *ap, t_print *info);
void	ft_parse_flag(char **fmt, t_print *info);
void	ft_parse_width(char **fmt, va_list *ap, t_print *info);
bool	ft_parse_spec(char **fmt, t_print *info);
bool	ft_parse_arg(va_list *ap, t_print *info);

// Sub Parsers
bool	ft_parse_char(va_list *ap, t_print *info);
bool	ft_parse_per(t_print *info);
bool	ft_parse_hex_lower(va_list *ap, t_print *info);
bool	ft_parse_hex_upper(va_list *ap, t_print *info);
bool	ft_parse_str(va_list *ap, t_print *info);
bool	ft_parse_ptr(va_list *ap, t_print *info);
bool	ft_parse_digit(va_list *ap, t_print *info);
bool	ft_parse_int(va_list *ap, t_print *info);
bool	ft_parse_uint(va_list *ap, t_print *info);

#endif
