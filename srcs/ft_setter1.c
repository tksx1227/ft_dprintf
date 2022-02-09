/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setter1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 12:01:17 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/10 00:43:11 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_status	ft_set_arg(va_list *ap, t_printf *info)
{
	char		spec;
	t_status	status;

	spec = info->spec;
	status = FAIL;
	if (spec == 'c')
		status = ft_set_char(ap, info);
	else if (spec == 's')
		status = ft_set_str(ap, info);
	else if (spec == 'p')
		status = ft_set_ptr(ap, info);
	else if (spec == 'i' || spec == 'd')
		status = ft_set_int(ap, info);
	else if (spec == 'u')
		status = ft_set_uint(ap, info);
	else if (spec == 'x' || spec == 'X')
		status = ft_set_hex(ap, info);
	else if (spec == '%')
		status = ft_set_per(info);
	return (status);
}

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
	if (n == 0)
		info->is_zero = true;
	s = ft_itoa_base_4bytes(n, 16, true);
	if (s == NULL)
		return (FAIL);
	info->content = s;
	info->length = ft_strlen(s);
	return (SUCCESS);
}
