/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 02:14:35 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/02 12:56:06 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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