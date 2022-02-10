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

static t_status	ft_attach_ptr_width_with_prefix(t_printf *info, char *prefix);

t_status	ft_attach_ptr(t_printf *info)
{
	t_status	status;

	status = SUCCESS;
	if ((info->is_zero && info->prec == 0) || info->length < info->prec)
		status = ft_attach_num_prec(info);
	if (status == SUCCESS)
	{
		if (info->length < info->width - 2)
			status = ft_attach_ptr_width_with_prefix(info, "0x");
		else
			status = ft_attach_prefix(info, "0x");
	}
	return (status);
}

static t_status	ft_attach_ptr_width_with_prefix(t_printf *info, char *prefix)
{
	size_t	offset;
	size_t	prefix_len;
	char	*content;

	content = (char *)ft_calloc((size_t)info->width + 1, sizeof(char));
	if (content == NULL)
		return (FAIL);
	if (info->zero_flag && info->prec == -1 && !info->left_align)
		ft_memset(content, '0', info->width);
	else
		ft_memset(content, ' ', info->width);
	prefix_len = ft_strlen(prefix);
	if (info->left_align)
		offset = prefix_len;
	else
		offset = info->width - info->length;
	if (info->zero_flag && info->prec == -1)
		ft_memmove(content, prefix, prefix_len);
	else
		ft_memmove(content + offset - prefix_len, prefix, prefix_len);
	ft_memmove(content + offset, info->content, info->length);
	free(info->content);
	info->content = content;
	info->length = info->width;
	return (SUCCESS);
}
