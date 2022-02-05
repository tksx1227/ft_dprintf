/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setter_sub_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 00:30:30 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/05 00:55:08 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static bool	ft_set_hex(va_list *ap, t_print *info);

bool	ft_set_char(va_list *ap, t_print *info)
{
	char	c;
	char	tmp[2];
	char	*s;

	c = (char)va_arg(*ap, int);
	if (c == '\0')
		info->is_null_char = true;
	tmp[0] = c;
	tmp[1] = '\0';
	s = ft_strdup(tmp);
	if (s == NULL)
		return (false);
	info->content = s;
	return (true);
}

bool	ft_set_per(t_print *info)
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

bool	ft_set_hex_lower(va_list *ap, t_print *info)
{
	return (ft_set_hex(ap, info));
}

bool	ft_set_hex_upper(va_list *ap, t_print *info)
{
	size_t	i;
	bool	is_success;

	is_success = ft_set_hex(ap, info);
	if (is_success)
	{
		i = 0;
		while (info->content[i] != '\0')
		{
			info->content[i] = ft_toupper(info->content[i]);
			i++;
		}
	}
	return (is_success);
}

static bool	ft_set_hex(va_list *ap, t_print *info)
{
	unsigned int	n;
	char			*s;

	n = (unsigned int)va_arg(*ap, unsigned int);
	s = ft_itoa_base_4b(n, 16, true);
	if (s == NULL)
		return (false);
	info->content = s;
	return (true);
}
