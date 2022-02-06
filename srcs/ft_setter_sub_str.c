/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setter_sub_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 00:38:29 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/06 15:09:09 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	ft_set_str(va_list *ap, t_printf *info)
{
	char	*s;

	s = (char *)va_arg(*ap, char *);
	if (s == NULL)
		s = ft_strdup("(null)");
	else
		s = ft_strdup(s);
	if (s == NULL)
		return (false);
	info->content = s;
	return (true);
}

bool	ft_set_ptr(va_list *ap, t_printf *info)
{
	char	*s;
	t_ull	n;

	n = (t_ull)va_arg(*ap, void *);
	s = ft_itoa_base_8bytes(n, 16, true);
	if (s == NULL)
		return (false);
	info->content = s;
	return (true);
}
