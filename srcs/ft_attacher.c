/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attacher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:12:52 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/06 14:20:55 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	ft_attacher(t_print *info)
{
	bool	is_success;

	is_success = ft_attach_prec(info);
	if (is_success && info->width != 0)
		is_success = ft_attach_width(info);
	if (is_success && info->plus_sign != 0)
		is_success = ft_attach_plus_sign(info);
	if (is_success && info->sharp_flag)
		is_success = ft_attach_sharp_flag(info);
	return (is_success);
}

bool	ft_attach_sharp_flag(t_print *info)
{
	char	*prefix;

	if (info->spec != 'x' && info->spec != 'X')
		return (false);
	if (info->spec == 'x')
		prefix = ft_strdup("0x");
	else
		prefix = ft_strdup("0X");
	if (prefix == NULL)
		return (false);
	info->content = add_prefix_with_free(info->content, prefix);
	if (info->content == NULL)
		return (false);
	return (true);
}

bool	ft_attach_plus_sign(t_print *info)
{
	char	tmp[2];
	char	*prefix;

	if (!info->is_number)
		return (false);
	if (info->content[0] != '-')
	{
		tmp[0] = info->plus_sign;
		tmp[1] = '\0';
		prefix = ft_strdup(tmp);
		if (prefix == NULL)
			return (false);
		info->content = add_prefix_with_free(info->content, prefix);
		if (info->content == NULL)
			return (false);
	}
	return (true);
}
