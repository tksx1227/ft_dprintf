/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attacher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 00:36:31 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/09 00:44:35 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_status	ft_attach(t_printf *info)
{
	char		spec;
	t_status	status;

	status = FAIL;
	spec = info->spec;
	if (spec == 's' || spec == 'c' || spec == '%')
		status = ft_attach_str(info);
	else if (spec == 'd' || spec == 'i' || spec == 'u')
		status = ft_attach_num(info);
	else if (spec == 'x' || spec == 'X')
		status = ft_attach_hex(info);
	else if (spec == 'p')
		status = ft_attach_ptr(info);
	return (status);
}
