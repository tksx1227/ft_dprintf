/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attacher_prec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:55:13 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/06 15:07:45 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	ft_attach_prec(t_printf *info)
{
	bool	is_success;

	if (info->spec != 'p' && info->prec < 0)
		return (true);
	if (info->spec == 'p')
		is_success = ft_attach_prec_ptr(info);
	else if (info->spec == 's')
		is_success = ft_attach_prec_str(info);
	else if (info->spec == 'x' || info->spec == 'X')
		is_success = ft_attach_prec_hex(info);
	else if (info->spec == 'd' || info->spec == 'i' || info->spec == 'u')
		is_success = ft_attach_prec_num(info);
	else
		is_success = true;
	return (is_success);
}

bool	ft_attach_prec_ptr(t_printf *info)
{
	size_t	len;
	char	*prefix;

	len = ft_strlen(info->content);
	if (info->prec < 0 || (size_t)info->prec <= len)
		len = 0;
	else
		len = (size_t)info->prec - len;
	prefix = (char *)ft_calloc(len + 3, sizeof(char));
	if (prefix == NULL)
		return (false);
	prefix[0] = '0';
	prefix[1] = 'x';
	ft_memset(prefix + 2, '0', len);
	info->content = add_prefix_with_free(info->content, prefix);
	if (info->content == NULL)
		return (false);
	return (true);
}

bool	ft_attach_prec_str(t_printf *info)
{
	size_t	len;
	char	*tmp;

	len = ft_strlen(info->content);
	if ((size_t)info->prec < len)
		len = info->prec;
	tmp = info->content;
	info->content = ft_substr(info->content, 0, len);
	free(tmp);
	if (info->content == NULL)
		return (false);
	return (true);
}

bool	ft_attach_prec_hex(t_printf *info)
{
	size_t	len;
	char	*prefix;

	len = ft_strlen(info->content);
	if (len < (size_t)info->prec)
	{
		len = (size_t)info->prec - len;
		prefix = (char *)ft_calloc(len + 1, sizeof(char));
		if (prefix == NULL)
			return (false);
		ft_memset(prefix, '0', len);
		info->content = add_prefix_with_free(info->content, prefix);
		if (info->content == NULL)
			return (false);
	}
	return (true);
}

bool	ft_attach_prec_num(t_printf *info)
{
	size_t	len;
	char	*prefix;

	if (0 <= info->prec && info->prec == 0 && info->is_zero)
	{
		prefix = ft_strdup("");
		if (prefix == NULL)
			return (false);
		free(info->content);
		info->content = prefix;
		return (true);
	}
	len = ft_strlen(info->content);
	if (0 <= info->prec && len < (size_t)info->prec)
	{
		len = (size_t)info->prec - len;
		prefix = (char *)ft_calloc(len + 1, sizeof(char));
		if (prefix == NULL)
			return (false);
		ft_memset(prefix, '0', len);
		info->content = add_prefix_with_free(info->content, prefix);
		if (info->content == NULL)
			return (false);
	}
	return (true);
}
