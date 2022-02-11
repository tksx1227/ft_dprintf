/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attacher_common.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 02:57:23 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/11 23:43:10 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_status	ft_attach_prefix_common(t_printf *info, char *prefix)
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

t_status	ft_attach_prec_common(t_printf *info)
{
	size_t	offset;
	char	*content;

	content = (char *)ft_calloc((size_t)info->prec + 1, sizeof(char));
	if (content == NULL)
		return (FAIL);
	if (!(info->is_zero && info->prec == 0))
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

t_status	ft_attach_width_with_prefix_common(t_printf *info, char *prefix)
{
	size_t	offset;
	size_t	prefix_len;
	char	*content;

	content = (char *)ft_calloc((size_t)info->width + 1, sizeof(char));
	if (content == NULL)
		return (FAIL);
	if (info->zero_flag && info->prec == INIT_PREC && !info->left_align)
		ft_memset(content, '0', info->width);
	else
		ft_memset(content, ' ', info->width);
	prefix_len = ft_strlen(prefix);
	if (info->left_align)
		offset = prefix_len;
	else
		offset = info->width - info->length;
	if (info->zero_flag && info->prec == INIT_PREC)
		ft_memmove(content, prefix, prefix_len);
	else
		ft_memmove(content + offset - prefix_len, prefix, prefix_len);
	ft_memmove(content + offset, info->content, info->length);
	free(info->content);
	info->content = content;
	info->length = info->width;
	return (SUCCESS);
}
