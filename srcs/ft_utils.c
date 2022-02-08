/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 02:14:35 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/09 02:35:14 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	add_write_count(int current, int new)
{
	if (current < 0 || new < 0 || INT_MAX - current < new)
		return (INVALID_NUM);
	return (current + new);
}

void	clear_info(t_printf *info, void (*del)(void *))
{
	info->width = 0;
	info->prec = -1;
	info->length = 0;
	info->spec = 0;
	info->sign = 0;
	info->is_zero = false;
	info->is_number = false;
	info->sharp_flag = false;
	info->left_align = false;
	info->zero_flag = false;
	if (del != NULL)
		del(info->content);
	info->content = NULL;
}

int	get_digits(char **fmt)
{
	t_ll	ret;

	ret = 0;
	while (ft_isdigit(**fmt))
	{
		if (ret != INVALID_NUM)
		{
			ret = ret * 10 + (**fmt - '0');
			if ((t_ll)INT_MAX < ret)
				ret = INVALID_NUM;
		}
		*fmt += 1;
	}
	return ((int)ret);
}

void	ft_toupper_str(char *s)
{
	while (*s != '\0')
	{
		ft_toupper(*s);
		s++;
	}
}
