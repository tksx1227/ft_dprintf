/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 10:28:29 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/06 15:10:23 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	int			wc;
	int			ret;
	va_list		ap;
	t_printf	info;

	ret = 0;
	va_start(ap, fmt);
	clear_info(&info, NULL);
	while (*fmt != '\0' && ret != -1)
	{
		if (*fmt == '%')
		{
			fmt++;
			if (ft_parse((char **)&fmt, &ap, &info))
				wc = ft_putval(&info, ret);
			else
				wc = -1;
			clear_info(&info, free);
		}
		else
			wc = ft_put2per((char **)&fmt);
		ret = add_write_count(ret, wc);
	}
	va_end(ap);
	return (ret);
}
