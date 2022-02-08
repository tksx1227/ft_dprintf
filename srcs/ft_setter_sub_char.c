/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setter_sub_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 00:30:30 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/08 13:27:31 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_status	ft_set_char(va_list *ap, t_printf *info)
{
	char	c;
	char	*s;

	c = (char)va_arg(*ap, int);
	s = ft_strdup(" ");
	if (s == NULL)
		return (FAIL);
	s[0] = c;
	info->content = s;
	info->length = 1;
	return (SUCCESS);
}

t_status	ft_set_per(t_printf *info)
{
	char	*s;

	s = ft_strdup("%");
	if (s == NULL)
		return (FAIL);
	info->content = s;
	info->length = 1;
	return (SUCCESS);
}

t_status	ft_set_hex(va_list *ap, t_printf *info)
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
