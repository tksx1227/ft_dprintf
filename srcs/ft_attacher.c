/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attacher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:12:52 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/04 01:56:05 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static bool	ft_attach_plus_space_base(t_print *info, char *s);

bool	ft_attacher(t_print *info)
{
	bool	is_success;

	is_success = ft_attach_prec(info);
	if (is_success && info->width != 0)
		is_success = ft_attach_width(info);
	if (is_success && info->plus_flag)
		is_success = ft_attach_plus_flag(info);
	if (is_success && !info->plus_flag && info->space_flag)
		is_success = ft_attach_space_flag(info);
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

bool	ft_attach_plus_flag(t_print *info)
{
	return (ft_attach_plus_space_base(info, "+"));
}

bool	ft_attach_space_flag(t_print *info)
{
	return (ft_attach_plus_space_base(info, " "));
}

static bool	ft_attach_plus_space_base(t_print *info, char *s)
{
	char	*prefix;

	if (!info->is_number)
		return (false);
	if (info->content[0] != '-')
	{
		prefix = ft_strdup(s);
		if (prefix == NULL)
			return (false);
		info->content = add_prefix_with_free(info->content, prefix);
		if (info->content == NULL)
			return (false);
	}
	return (true);
}
