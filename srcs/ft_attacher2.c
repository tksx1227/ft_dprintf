/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attacher2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 02:39:51 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/11 23:42:35 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_toupper_str(char *s);

t_status	ft_attach_num(t_printf *info)
{
	int			prefix_len;
	char		prefix[2];
	t_status	status;

	status = SUCCESS;
	if ((info->is_zero && info->prec == 0) || info->length < info->prec)
		status = ft_attach_prec_common(info);
	if (status == SUCCESS)
	{
		prefix[0] = info->sign;
		prefix[1] = '\0';
		prefix_len = (int)ft_strlen(prefix);
		if (info->length < info->width - prefix_len)
			status = ft_attach_width_with_prefix_common(info, prefix);
		else
			status = ft_attach_prefix_common(info, prefix);
	}
	return (status);
}

t_status	ft_attach_ptr(t_printf *info)
{
	t_status	status;

	status = SUCCESS;
	if ((info->is_zero && info->prec == 0) || info->length < info->prec)
		status = ft_attach_prec_common(info);
	if (status == SUCCESS)
	{
		if (info->length < info->width - 2)
			status = ft_attach_width_with_prefix_common(info, "0x");
		else
			status = ft_attach_prefix_common(info, "0x");
	}
	return (status);
}

t_status	ft_attach_hex(t_printf *info)
{
	t_status	status;

	status = SUCCESS;
	if ((info->is_zero && info->prec == 0) || info->length < info->prec)
		status = ft_attach_prec_common(info);
	if (status == SUCCESS)
	{
		if (info->sharp_flag && !info->is_zero)
		{
			if (info->length < info->width - 2)
				status = ft_attach_width_with_prefix_common(info, "0x");
			else
				status = ft_attach_prefix_common(info, "0x");
		}
		else
		{
			if (info->length < info->width)
				status = ft_attach_width_with_prefix_common(info, "");
		}
	}
	if (status == SUCCESS && info->spec == 'X')
		ft_toupper_str(info->content);
	return (status);
}

static void	ft_toupper_str(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		s[i] = (char)ft_toupper(s[i]);
		i++;
	}
}
