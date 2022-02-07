/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attacher_prec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:55:13 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/08 02:05:13 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_status	ft_attach_prec(t_printf *info)
{
	t_status	status;

	if (info->spec != 'p' && info->prec < 0)
		return (SUCCESS);
	status = SUCCESS;
	if (info->spec == 's')
		status = ft_attach_prec_str(info);
	else if (info->spec == 'p')
		status = ft_attach_prec_ptr(info);
	else if (info->spec == 'x' || info->spec == 'X')
		status = ft_attach_prec_hex(info);
	else if (info->spec == 'd' || info->spec == 'i' || info->spec == 'u')
		status = ft_attach_prec_num(info);
		
	return (status);
}

t_status	ft_attach_prec_ptr(t_printf *info)
{
	size_t	len;
	char	*prefix;

	if (info->prec < 0 || info->prec <= info->length)
		len = 0;
	else
		len = info->prec - info->length;
	prefix = (char *)ft_calloc(len + 3, sizeof(char));
	if (prefix == NULL)
		return (FAIL);
	prefix[0] = '0';
	prefix[1] = 'x';
	ft_memset(prefix + 2, '0', len);
	info->content = add_prefix_with_free(info->content, prefix);
	if (info->content == NULL)
		return (FAIL);
	return (SUCCESS);
}

t_status	ft_attach_prec_str(t_printf *info)
{
	int		len;
	char	*tmp;

	if (info->prec < info->length)
		len = info->prec;
	tmp = info->content;
	info->content = ft_substr(info->content, 0, len);
	free(tmp);
	if (info->content == NULL)
		return (FAIL);
	return (SUCCESS);
}

t_status	ft_attach_prec_hex(t_printf *info)
{
	int		len;
	char	*prefix;

	if (info->length < info->prec)
	{
		len = info->prec - info->length;
		prefix = (char *)ft_calloc(len + 1, sizeof(char));
		if (prefix == NULL)
			return (FAIL);
		ft_memset(prefix, '0', len);
		info->content = add_prefix_with_free(info->content, prefix);
		if (info->content == NULL)
			return (FAIL);
	}
	return (SUCCESS);
}

t_status	ft_attach_prec_num(t_printf *info)
{
	size_t	len;
	char	*prefix;

	if (0 <= info->prec && info->prec == 0 && info->is_zero)
	{
		prefix = ft_strdup("");
		if (prefix == NULL)
			return (FAIL);
		free(info->content);
		info->content = prefix;
		return (SUCCESS);
	}
	len = ft_strlen(info->content);
	if (0 <= info->prec && len < (size_t)info->prec)
	{
		len = (size_t)info->prec - len;
		prefix = (char *)ft_calloc(len + 1, sizeof(char));
		if (prefix == NULL)
			return (FAIL);
		ft_memset(prefix, '0', len);
		info->content = add_prefix_with_free(info->content, prefix);
		if (info->content == NULL)
			return (FAIL);
	}
	return (SUCCESS);
}
