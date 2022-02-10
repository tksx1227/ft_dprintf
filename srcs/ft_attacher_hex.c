/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attacher_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 01:50:49 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/10 03:23:14 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_status	ft_attach_hex_width_with_prefix(t_printf *info);

t_status	ft_attach_hex(t_printf *info)
{
	t_status	status;

	status = SUCCESS;
	if (info->length < info->prec)
		status = ft_attach_num_prec(info);
	if (status == SUCCESS)
	{
		if (info->sharp_flag && !info->is_zero)
		{
			if (info->length < info->width - 2)
				status = ft_attach_hex_width_with_prefix(info);
			else
				status = ft_attach_prefix(info, "0x");
		}
		else
		{
			if (info->length < info->width)
				status = ft_attach_num_width(info);
		}
	}
	if (status == SUCCESS && info->spec == 'X')
		ft_toupper_str(info->content);
	return (status);
}

static t_status	ft_attach_hex_width_with_prefix(t_printf *info)
{
	size_t	offset;
	char	*content;

	content = (char *)ft_calloc((size_t)info->width + 1, sizeof(char));
	if (content == NULL)
		return (FAIL);
	ft_memset(content, ' ', info->width);
	if (info->left_align)
		offset = 2;
	else
		offset = info->width - info->length;
	ft_memmove(content + offset - 2, "0x", 2);
	ft_memmove(content + offset, info->content, info->length);
	free(info->content);
	info->content = content;
	info->length = info->width;
	return (SUCCESS);
}
