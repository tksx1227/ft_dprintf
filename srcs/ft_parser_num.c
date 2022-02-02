/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 00:31:19 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/03 02:01:58 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

bool	ft_parse_digit(va_list *ap, t_print *info)
{
	int		n;
	char	*s;

	n = (int)va_arg(*ap, int);
	if (n == 0)
		info->is_zero = true;
	s = ft_itoa_base(n, 10, true);
	if (s == NULL)
		return (false);
	info->content = s;
	info->is_number = true;
	return (true);
}

bool	ft_parse_int(va_list *ap, t_print *info)
{
	return (ft_parse_digit(ap, info));
}

bool	ft_parse_uint(va_list *ap, t_print *info)
{
	char			*s;
	unsigned int	n;

	n = (unsigned int)va_arg(*ap, unsigned int);
	if (n == 0)
		info->is_zero = true;
	s = ft_itoa_base(n, 10, true);
	if (s == NULL)
		return (false);
	info->content = s;
	info->is_number = true;
	return (true);
}
