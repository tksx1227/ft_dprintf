/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putval.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 01:41:26 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/06 15:08:26 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put2per(char **s)
{
	ssize_t	ret;
	size_t	len;

	len = 0;
	while ((*s)[len] != '\0' && (*s)[len] != '%')
		len++;
	if ((size_t)INT_MAX < len)
		return (-1);
	ret = write(1, *s, len);
	if (ret != -1)
		*s += ret;
	return ((int)ret);
}

int	ft_putval(t_printf *info, int wc)
{
	size_t	len;

	len = ft_strlen(info->content);
	if (info->is_null_char)
		len++;
	if ((size_t)INT_MAX - len < (size_t)wc)
		return (-1);
	write(1, info->content, len);
	return (len);
}
