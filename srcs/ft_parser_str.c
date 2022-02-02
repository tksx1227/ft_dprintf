/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 00:38:29 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/02 13:57:38 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

bool	ft_parse_str(va_list *ap, t_print *info)
{
	char	*s;

	s = ft_strdup((char *)va_arg(*ap, char *));
	if (s == NULL)
		return (false);
	info->content = s;
	return (true);
}

bool	ft_parse_ptr(va_list *ap, t_print *info)
{
	char				*s;
	char				*prefix;
	unsigned long long	n;

	n = (unsigned long long)va_arg(*ap, void *);
	s = ft_itoa_base(n, 16, true);
	if (s == NULL)
		return (false);
	prefix = ft_strdup("0x");
	if (prefix == NULL)
		return (false);
	s = add_prefix_with_free(s, prefix);
	if (s == NULL)
		return (false);
	info->content = s;
	return (true);
}