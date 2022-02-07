/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 02:14:35 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/08 02:54:42 by ttomori          ###   ########.fr       */
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
	info->plus_sign = 0;
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

char	*add_prefix_with_free(char *s, char *prefix)
{
	char	*new;

	new = ft_strjoin(prefix, s);
	free(s);
	free(prefix);
	if (new == NULL)
		return (NULL);
	return (new);
}

char	*add_suffix_with_free(char *s, char *suffix)
{
	char	*new;

	new = ft_strjoin(s, suffix);
	free(s);
	free(suffix);
	if (new == NULL)
		return (NULL);
	return (new);
}
