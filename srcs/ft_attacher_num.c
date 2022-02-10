/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attacher_num.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 02:39:51 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/10 03:20:53 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_status	ft_attach_num(t_printf *info)
{
	char		prefix[2];
	t_status	status;

	status = SUCCESS;
	if ((info->is_zero && info->prec == 0) || info->length < info->prec)
		status = ft_attach_num_prec(info);
	if (status == SUCCESS)
	{
		if (info->sign != 0 && !info->is_unsigned)
		{
			prefix[0] = info->sign;
			prefix[1] = '\0';
			if (info->length < info->width - 1)
				status = ft_attach_num_width_with_prefix(info, prefix);
			else
				status = ft_attach_prefix(info, prefix);
		}
		else
		{
			if (info->length < info->width)
				status = ft_attach_num_width(info);
		}
	}
	return (status);
}
