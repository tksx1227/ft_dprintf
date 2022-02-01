/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 23:00:32 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/02 00:35:59 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

bool ft_parser(char **fmt, va_list *ap, t_print *info)
{
	bool is_success;

	ft_parse_flag(fmt, info);
	ft_parse_width(fmt, ap, info);
	is_success = ft_parse_spec(fmt, info);
	if (is_success)
		is_success = ft_parse_arg(ap, info);
	return (is_success);
}

void	ft_parse_flag(char **fmt, t_print *info)
{
	char	flag;

	flag = **fmt;
	if (flag == '-')
		info->minus_flag = true;
	else if (flag == '0')
		info->zero_flag = true;
	else if (flag == '.')
		info->dot_flag = true;
	else if (flag == '#')
		info->sharp_flag = true;
	else if (flag == ' ')
		info->space_flag = true;
	else if (flag == '+')
		info->plus_flag = true;
	else
		return ;
	*fmt += 1;
	ft_parse_flag(fmt, info);
}

void	ft_parse_width(char **fmt, va_list *ap, t_print *info)
{
	size_t	width;

	width = 0;
	if (**fmt == '*')
	{
		width = (int)va_arg(*ap, int);
		if (width < 0)
		{
			width *= -1;
			info->minus_flag = true;
		}
		*fmt += 1;
	}
	else
	{
		while (ft_isdigit(**fmt))
		{
			width = width * 10 + (**fmt - '0');
			*fmt += 1;
		}
	}
	if ((size_t)INT_MAX < width)
		info->width = -1;
	else
		info->width = width;
}

bool	ft_parse_spec(char **fmt, t_print *info)
{
	char	spec;

	spec = **fmt;
	if (spec == 'c' || spec == 's' || spec == 'p' || spec == 'd' || spec == 'i' \
			|| spec == 'u' || spec == 'x' || spec == 'X' || spec == '%')
	{
		info->spec = spec;
		*fmt += 1;
		return (true);
	}
	return (false);
}

bool	ft_parse_arg(va_list *ap, t_print *info)
{
	char	spec;
	bool	is_success;

	spec = info->spec;
	if (spec == 'c')
		is_success = ft_parse_char(ap, info);
	else if (spec == 's')
		is_success = ft_parse_str(ap, info);
	else if (spec == 'p')
		is_success = ft_parse_ptr(ap, info);
	else if (spec == 'd')
		is_success = ft_parse_digit(ap, info);
	else if (spec == 'i')
		is_success = ft_parse_int(ap, info);
	else if (spec == 'u')
		is_success = ft_parse_uint(ap, info);
	else if (spec == 'x')
		is_success = ft_parse_hex_lower(ap, info);
	else if (spec == 'X')
		is_success = ft_parse_hex_upper(ap, info);
	else if (spec == '%')
		is_success = ft_parse_per(info);
	else
		is_success = false;
	return (is_success);
}
