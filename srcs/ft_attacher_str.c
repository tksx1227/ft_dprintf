/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attacher_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 01:47:24 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/08 02:33:18 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_status	ft_attach_str_prec(t_printf *info);
static t_status	ft_attach_str_width(t_printf *info);

t_status	ft_attach_str(t_printf *info)
{
	int			len;
	char		*tmp;
	t_status	status;

	if (info->prec < info->length)
		status = ft_attach_str_prec(info);
	if (status == SUCCESS && info->length < info->width)
		status = ft_attach_str_width(info);
	return (status);
}

static t_status	ft_attach_str_prec(t_printf *info)
{
	char	*tmp;

	info->length = info->prec;
	tmp = info->content;
	info->content = ft_substr(info->content, 0, info->length);
	free(tmp);
	if (info->content == NULL)
		return (FAIL);
	return (SUCCESS);
}

static t_status	ft_attach_str_width(t_printf *info)
{
	size_t	offset;
	char	*content;

	content = (char *)ft_calloc((size_t)info->width + 1, sizeof(char));
	if (content == NULL)
		return (FAIL);
	ft_memset(content, ' ', info->width);
	if (info->left_align)
		offset = info->width - info->length;
	else
		offset = 0;
	ft_memmove(content + offset, info->content, info->length);
	free(info->content);
	info->content = content;
	info->length = info->width;
	return (SUCCESS);
}
