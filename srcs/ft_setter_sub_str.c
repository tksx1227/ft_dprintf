/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setter_sub_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 00:38:29 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/08 02:12:03 by ttomori          ###   ########.fr       */
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
	char	*s;
	t_ull	n;

	n = (t_ull)va_arg(*ap, void *);
	s = ft_itoa_base_8bytes(n, 16, true);
	if (s == NULL)
		return (FAIL);
	info->content = s;
	info->length = ft_strlen(s);
	return (SUCCESS);
}
