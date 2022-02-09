/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attacher_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 02:57:23 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/10 03:21:46 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_status	ft_attach_prefix(t_printf *info, char *prefix)
{
	char	*temp;

	temp = info->content;
	info->content = ft_strjoin(prefix, info->content);
	free(temp);
	if (info->content == NULL)
		return (FAIL);
	info->length += ft_strlen(prefix);
	return (SUCCESS);
}

t_status	ft_attach_num_prec(t_printf *info)
{
	size_t	offset;
	char	*content;

	content = (char *)ft_calloc((size_t)info->prec + 1, sizeof(char));
	if (content == NULL)
		return (FAIL);
	if (info->is_zero && info->prec == 0)
	{
		ft_memset(content, 0, 1);
	}
	else
	{
		ft_memset(content, '0', info->prec);
		offset = info->prec - info->length;
		ft_memmove(content + offset, info->content, info->length);
	}
	free(info->content);
	info->content = content;
	info->length = info->prec;
	return (SUCCESS);
}
