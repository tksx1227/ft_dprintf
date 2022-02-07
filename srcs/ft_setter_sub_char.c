/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setter_sub_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 00:30:30 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/08 02:10:28 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_status	ft_set_hex(va_list *ap, t_printf *info);

t_status	ft_set_char(va_list *ap, t_printf *info)
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
		return (FAIL);
	info->content = s;
	info->length = 1;
	return (SUCCESS);
}

t_status	ft_set_per(t_printf *info)
{
	char	tmp[2];
	char	*s;

	tmp[0] = '%';
	tmp[1] = '\0';
	s = ft_strdup(tmp);
	if (s == NULL)
		return (FAIL);
	info->content = s;
	info->length = 1;
	return (SUCCESS);
}

t_status	ft_set_hex_lower(va_list *ap, t_printf *info)
{
	return (ft_set_hex(ap, info));
}

t_status	ft_set_hex_upper(va_list *ap, t_printf *info)
{
	size_t		i;
	t_status	status;

	status = ft_set_hex(ap, info);
	if (status == SUCCESS)
	{
		i = 0;
		while (info->content[i] != '\0')
		{
			info->content[i] = ft_toupper(info->content[i]);
			i++;
		}
	}
	return (status);
}

static t_status	ft_set_hex(va_list *ap, t_printf *info)
{
	unsigned int	n;
	char			*s;

	n = (unsigned int)va_arg(*ap, unsigned int);
	s = ft_itoa_base_4bytes(n, 16, true);
	if (s == NULL)
		return (FAIL);
	info->content = s;
	info->length = ft_strlen(s);
	return (SUCCESS);
}
