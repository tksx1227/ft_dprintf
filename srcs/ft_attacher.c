/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attacher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:12:52 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/02 13:20:23 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static bool	ft_attach_plus_space_base(t_print *info, char *s);

bool	ft_attacher(t_print *info)
{
	bool	is_success;

	is_success = true;
	if (is_success && info->plus_flag)
		is_success = ft_attach_plus_flag(info);
	if (is_success && info->sharp_flag)
		is_success = ft_attach_sharp_flag(info);
	if (is_success && info->minus_flag)
		is_success = ft_attach_minus_flag(info);
	if (is_success && !info->plus_flag && info->space_flag)
		is_success = ft_attach_space_flag(info);
	if (is_success && !info->minus_flag && info->zero_flag)
		is_success = ft_attach_zero_flag(info);
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
		prefix = ft_strdup("0x");
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

	if (info->spec != 'd' && info->spec != 'i')
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
