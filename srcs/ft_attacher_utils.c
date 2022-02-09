/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attacher_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 02:57:23 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/10 02:58:41 by ttomori          ###   ########.fr       */
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
