/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attacher_ptr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 00:46:47 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/10 17:57:19 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_status	ft_attach_ptr(t_printf *info)
{
	t_status	status;

	status = SUCCESS;
	if ((info->is_zero && info->prec == 0) || info->length < info->prec)
		status = ft_attach_num_prec(info);
	if (status == SUCCESS)
	{
		if (info->length < info->width - 2)
			status = ft_attach_num_width_with_prefix(info, "0x");
		else
			status = ft_attach_prefix(info, "0x");
	}
	return (status);
}
