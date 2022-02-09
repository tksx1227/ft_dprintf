/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attacher_ptr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 00:46:47 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/10 03:23:25 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_status	ft_attach_ptr_prec(t_printf *info);
static t_status	ft_attach_ptr_width_with_prefix(t_printf *info);

t_status	ft_attach_ptr(t_printf *info)
{
	t_status	status;

	status = SUCCESS;
	if (info->length < info->prec)
		status = ft_attach_ptr_prec(info);
	if (status == SUCCESS)
	{
		if (info->length < info->width - 2)
			status = ft_attach_ptr_width_with_prefix(info);
		else
			status = ft_attach_prefix(info, "0x");
	}
	return (status);
}

static t_status	ft_attach_ptr_width_with_prefix(t_printf *info)
{
	size_t	offset;
	char	*content;

	content = (char *)ft_calloc((size_t)info->width + 1, sizeof(char));
	if (content == NULL)
		return (FAIL);
	if (info->zero_flag && !info->left_align)
		ft_memset(content, '0', info->width);
	else
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
