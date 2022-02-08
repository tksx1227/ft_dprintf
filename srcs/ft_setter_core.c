/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setter_core.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 12:01:17 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/08 13:30:05 by ttomori          ###   ########.fr       */
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
