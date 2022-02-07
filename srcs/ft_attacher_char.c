/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attacher_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 01:30:45 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/08 01:40:40 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	ft_attach_char(t_printf *info)
{
	char	*s;

	if (1 < info->width)
	{
		s = (char *)ft_calloc((size_t)info->width + 1, sizeof(char));
		if (s == NULL)
			return (false);
		ft_memset(s, ' ', info->width);
		if (info->left_align)
			s[info->width - 1] = info->content[0];
		else
			s[0] = info->content[0];
		free(info->content);
		info->content = s;
		info->length = info->width;
	}
	return (true);
}
