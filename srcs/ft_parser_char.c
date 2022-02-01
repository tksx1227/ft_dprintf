/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 00:30:30 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/02 00:39:36 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static bool	ft_parse_hex(va_list *ap, t_print *info, bool islower);

bool	ft_parse_char(va_list *ap, t_print *info)
{
	char	c;
	char	tmp[2];
	char	*s;

	c = (char)va_arg(*ap, int);
	tmp[0] = c;
	tmp[1] = '\0';
	s = ft_strdup(tmp);
	if (s == NULL)
		return (false);
	info->content = s;
	return (true);
}

bool	ft_parse_per(t_print *info)
{
	char	tmp[2];
	char	*s;

	tmp[0] = '%';
	tmp[1] = '\0';
	s = ft_strdup(tmp);
	if (s == NULL)
		return (false);
	info->content = s;
	return (true);
}

bool	ft_parse_hex_lower(va_list *ap, t_print *info)
{
	return (ft_parse_hex(ap, info, true));
}

bool	ft_parse_hex_upper(va_list *ap, t_print *info)
{
	return (ft_parse_hex(ap, info, false));
}

static bool	ft_parse_hex(va_list *ap, t_print *info, bool islower)
{
	unsigned int	n;
	char			*s;

	n = (unsigned int)va_arg(*ap, unsigned int);
	s = ft_itoa_base(n, 16, islower);
	if (s == NULL)
		return (false);
	info->content = s;
	return (true);
}
