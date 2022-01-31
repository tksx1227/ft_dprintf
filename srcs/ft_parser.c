/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 23:00:32 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/01 00:32:27 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_parse_flag(char **fmt, t_print *info)
{
	char	flag;

	flag = **fmt;
	if (flag == '-')
		info->minus_flag = true;
	else if (flag == '0')
		info->zero_flag = true;
	else if (flag == '.')
		info->dot_flag = true;
	else if (flag == '#')
		info->sharp_flag = true;
	else if (flag == ' ')
		info->space_flag = true;
	else if (flag == '+')
		info->plus_flag = true;
	else
		return ;
	*fmt += 1;
	ft_parse_flag(fmt, info);
}
