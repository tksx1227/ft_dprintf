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

static t_status	ft_attach_num_width(t_printf *info);
static t_status	ft_attach_num_width_with_sign(t_printf *info);

t_status	ft_attach_num(t_printf *info)
{
	char		prefix[2];
	t_status	status;

	status = SUCCESS;
	if ((info->is_zero && info->prec == 0) || info->length < info->prec)
		status = ft_attach_num_prec(info);
	if (status == SUCCESS)
	{
		if (info->sign != 0)
		{
			prefix[0] = info->sign;
			prefix[1] = '\0';
			if (info->length < info->width - 1)
				status = ft_attach_num_width_with_sign(info);
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

static t_status	ft_attach_num_width(t_printf *info)
{
	size_t	offset;
	char	*content;

	content = (char *)ft_calloc((size_t)info->width + 1, sizeof(char));
	if (content == NULL)
		return (FAIL);
	if (info->zero_flag && info->prec == -1 && !info->left_align)
		ft_memset(content, '0', info->width);
	else
		ft_memset(content, ' ', info->width);
	if (info->left_align)
		offset = 0;
	else
		offset = info->width - info->length;
	ft_memmove(content + offset, info->content, info->length);
	free(info->content);
	info->content = content;
	info->length = info->width;
	return (SUCCESS);
}

static t_status	ft_attach_num_width_with_sign(t_printf *info)
{
	size_t	offset;
	char	*content;

	content = (char *)ft_calloc((size_t)info->width + 1, sizeof(char));
	if (content == NULL)
		return (FAIL);
	if (info->zero_flag && info->prec == -1 && !info->left_align)
		ft_memset(content, '0', info->width);
	else
		ft_memset(content, ' ', info->width);
	if (info->left_align)
		offset = 1;
	else
		offset = info->width - info->length;
	if (info->zero_flag && info->prec == -1)
		content[0] = info->sign;
	else
		content[offset - 1] = info->sign;
	ft_memmove(content + offset, info->content, info->length);
	free(info->content);
	info->content = content;
	info->length = info->width;
	return (SUCCESS);
}
