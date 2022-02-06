/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setter_core.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 12:01:17 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/06 15:08:38 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	ft_set_arg(va_list *ap, t_printf *info)
{
	char	spec;
	bool	is_success;

	spec = info->spec;
	if (spec == 'c')
		is_success = ft_set_char(ap, info);
	else if (spec == 's')
		is_success = ft_set_str(ap, info);
	else if (spec == 'p')
		is_success = ft_set_ptr(ap, info);
	else if (spec == 'd')
		is_success = ft_set_digit(ap, info);
	else if (spec == 'i')
		is_success = ft_set_int(ap, info);
	else if (spec == 'u')
		is_success = ft_set_uint(ap, info);
	else if (spec == 'x')
		is_success = ft_set_hex_lower(ap, info);
	else if (spec == 'X')
		is_success = ft_set_hex_upper(ap, info);
	else if (spec == '%')
		is_success = ft_set_per(info);
	else
		is_success = false;
	return (is_success);
}
