/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attacher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:12:52 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/08 02:01:29 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_status	ft_attacher(t_printf *info)
{
	t_status	status;

	status = ft_attach_prec(info);
	if (status == SUCCESS && info->width != 0)
		status = ft_attach_width(info);
	if (status == SUCCESS && info->plus_sign != 0)
		status = ft_attach_plus_sign(info);
	if (status == SUCCESS && info->sharp_flag)
		status = ft_attach_sharp_flag(info);
	return (status);
}

t_status	ft_attach_sharp_flag(t_printf *info)
{
	char	*prefix;

	if (info->spec != 'x' && info->spec != 'X')
		return (FAIL);
	if (info->spec == 'x')
		prefix = ft_strdup("0x");
	else
		prefix = ft_strdup("0X");
	if (prefix == NULL)
		return (FAIL);
	info->content = add_prefix_with_free(info->content, prefix);
	if (info->content == NULL)
		return (FAIL);
	return (SUCCESS);
}

t_status	ft_attach_plus_sign(t_printf *info)
{
	char	tmp[2];
	char	*prefix;

	if (!info->is_number)
		return (FAIL);
	if (info->content[0] != '-')
	{
		tmp[0] = info->plus_sign;
		tmp[1] = '\0';
		prefix = ft_strdup(tmp);
		if (prefix == NULL)
			return (FAIL);
		info->content = add_prefix_with_free(info->content, prefix);
		if (info->content == NULL)
			return (FAIL);
	}
	return (SUCCESS);
}
