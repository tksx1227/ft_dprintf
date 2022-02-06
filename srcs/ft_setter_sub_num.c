/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setter_sub_num.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 00:31:19 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/06 15:09:23 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	ft_set_digit(va_list *ap, t_printf *info)
{
	int		n;
	char	*s;

	n = (int)va_arg(*ap, int);
	if (n == 0)
		info->is_zero = true;
	s = ft_itoa_base_4bytes(n, 10, false);
	if (s == NULL)
		return (false);
	info->content = s;
	info->is_number = true;
	return (true);
}

bool	ft_set_int(va_list *ap, t_printf *info)
{
	return (ft_set_digit(ap, info));
}

bool	ft_set_uint(va_list *ap, t_printf *info)
{
	char			*s;
	unsigned int	n;

	n = (unsigned int)va_arg(*ap, unsigned int);
	if (n == 0)
		info->is_zero = true;
	s = ft_itoa_base_4bytes(n, 10, true);
	if (s == NULL)
		return (false);
	info->content = s;
	info->is_number = true;
	return (true);
}
