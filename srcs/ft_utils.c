/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 02:14:35 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/03 01:40:23 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	clear_info(t_print *info, void (*del)(void *))
{
	info->width = 0;
	info->prec = -1;
	info->spec = 0;
	info->is_zero = false;
	info->is_number = false;
	info->sharp_flag = false;
	info->space_flag = false;
	info->plus_flag = false;
	info->minus_flag = false;
	info->zero_flag = false;
	if (del != NULL)
		del(info->content);
	info->content = NULL;
}

int	get_digit_part(char **fmt)
{
	long long	ret;

	ret = 0;
	while (ft_isdigit(**fmt))
	{
		if (ret != -1)
		{
			ret = ret * 10 + (**fmt - '0');
			if ((long long)INT_MAX < ret)
				ret = -1;
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
