/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 02:14:35 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/02 02:14:55 by ttomori          ###   ########.fr       */
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
