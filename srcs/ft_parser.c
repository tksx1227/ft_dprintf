/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 23:00:32 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/06 14:17:00 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_parse_flags(char **fmt, t_print *info);
static void	ft_parse_width(char **fmt, va_list *ap, t_print *info);
static void	ft_parse_precision(char **fmt, va_list *ap, t_print *info);
static void	ft_parse_spec(char **fmt, t_print *info);

bool	ft_parse(char **fmt, va_list *ap, t_print *info)
{
	bool	is_success;

	ft_parse_flags(fmt, info);
	ft_parse_width(fmt, ap, info);
	ft_parse_precision(fmt, ap, info);
	ft_parse_spec(fmt, info);
	is_success = ft_set_arg(ap, info);
	return (is_success);
}

static void	ft_parse_flags(char **fmt, t_print *info)
{
	char	c;

	while (1)
	{
		c = **fmt;
		if (c == '-')
			info->left_align = true;
		else if (c == '0')
			info->zero_flag = true;
		else if (c == '#')
			info->sharp_flag = true;
		else if (c == '+')
			info->plus_sign = '+';
		else if (c == ' ')
		{
			if (info->plus_sign == 0)
				info->plus_sign = ' ';
		}
		else
			break ;
		*fmt += 1;
	}
}

static void	ft_parse_width(char **fmt, va_list *ap, t_print *info)
{
	int	width;

	if (**fmt == '*')
	{
		width = (int)va_arg(*ap, int);
		if (width < 0)
		{
			width *= -1;
			info->left_align = true;
		}
		*fmt += 1;
	}
	else
	{
		width = get_digits(fmt);
	}
	info->width = width;
}

static void	ft_parse_precision(char **fmt, va_list *ap, t_print *info)
{
	int	prec;

	if (**fmt != '.')
		return ;
	*fmt += 1;
	if (**fmt == '*')
	{
		*fmt += 1;
		prec = (int)va_arg(*ap, int);
	}
	else if (ft_isdigit(**fmt))
	{
		prec = get_digits(fmt);
	}
	else
	{
		prec = 0;
	}
	if (0 <= prec)
		info->prec = prec;
}

static void	ft_parse_spec(char **fmt, t_print *info)
{
	char	spec;

	spec = **fmt;
	if (spec == 'c' || spec == 's' || spec == 'p' || spec == 'd' || spec == 'i' \
			|| spec == 'u' || spec == 'x' || spec == 'X' || spec == '%')
	{
		info->spec = spec;
		*fmt += 1;
	}
}
