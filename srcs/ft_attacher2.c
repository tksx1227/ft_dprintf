/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attacher2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 23:09:19 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/06 15:07:37 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static bool	ft_attach_width_zero_base(t_printf *info, char c);

bool	ft_attach_width(t_printf *info)
{
	if (info->zero_flag && info->is_number)
		return (ft_attach_zero_flag(info));
	else
		return (ft_attach_width_zero_base(info, ' '));
}

bool	ft_attach_zero_flag(t_printf *info)
{
	if (info->prec != -1)
		return (true);
	return (ft_attach_width_zero_base(info, '0'));
}

static bool	ft_attach_width_zero_base(t_printf *info, char c)
{
	size_t	len;
	char	*s;

	if (info->width < 0)
		return (false);
	if (info->prec == 0 && info->is_zero)
		return (true);
	len = ft_strlen(info->content);
	if (len < (size_t)info->width)
	{
		len = (size_t)info->width - len;
		if (0 < len && info->plus_sign != 0)
			len--;
		s = (char *)ft_calloc(len + 1, sizeof(char));
		if (s == NULL)
			return (false);
		ft_memset(s, c, len);
		if (info->left_align)
			info->content = add_suffix_with_free(info->content, s);
		else
			info->content = add_prefix_with_free(info->content, s);
		if (info->content == NULL)
			return (false);
	}
	return (true);
}
