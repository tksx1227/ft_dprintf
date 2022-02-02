/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:20:38 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/03 02:20:26 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	ft_parser(char **fmt, va_list *ap, t_print *info)
{
	bool	is_success;

	ft_parse_flag(fmt, info);
	ft_parse_width(fmt, ap, info);
	ft_parse_precision(fmt, ap, info);
	is_success = ft_parse_spec(fmt, info);
	if (is_success)
		is_success = ft_parse_arg(ap, info);
	return (is_success);
}
