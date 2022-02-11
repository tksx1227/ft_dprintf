/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setter2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:38:34 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/11 23:43:36 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_status	ft_set_str(va_list *ap, t_printf *info)
{
	size_t	len;
	char	*s;

	s = (char *)va_arg(*ap, char *);
	if (s == NULL)
		s = ft_strdup("(null)");
	else
		s = ft_strdup(s);
	if (s == NULL)
		return (FAIL);
	len = ft_strlen(s);
	if ((size_t)INT_MAX < len)
		info->length = -1;
	else
		info->length = len;
	info->content = s;
	return (SUCCESS);
}

t_status	ft_set_ptr(va_list *ap, t_printf *info)
{
	char				*s;
	unsigned long long	n;

	n = (unsigned long long)va_arg(*ap, void *);
	if (n == 0)
		info->is_zero = true;
	s = ft_itoa_base_8bytes(n, 16, true);
	if (s == NULL)
		return (FAIL);
	info->content = s;
	info->length = ft_strlen(s);
	return (SUCCESS);
}

t_status	ft_set_int(va_list *ap, t_printf *info)
{
	char		*s;
	long long	n;

	n = (int)va_arg(*ap, int);
	if (n == 0)
		info->is_zero = true;
	if (n < 0)
	{
		info->sign = '-';
		n = -n;
	}
	s = ft_itoa_base_8bytes(n, 10, false);
	if (s == NULL)
		return (FAIL);
	info->content = s;
	info->length = ft_strlen(s);
	return (SUCCESS);
}

t_status	ft_set_uint(va_list *ap, t_printf *info)
{
	char			*s;
	unsigned int	n;

	n = (unsigned int)va_arg(*ap, unsigned int);
	if (n == 0)
		info->is_zero = true;
	s = ft_itoa_base_4bytes(n, 10, true);
	if (s == NULL)
		return (FAIL);
	info->content = s;
	info->length = ft_strlen(s);
	return (SUCCESS);
}
