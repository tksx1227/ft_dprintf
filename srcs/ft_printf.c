/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 10:28:29 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/11 02:04:31 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put2per(char **s);
static int	ft_putval(t_printf *info, int wc);
static int	ft_add_write_count(int current, int new);
static void	ft_clear_info(t_printf *info, void (*del)(void *));

int	ft_printf(const char *fmt, ...)
{
	int			wc;
	int			ret;
	va_list		ap;
	t_printf	info;

	ret = 0;
	va_start(ap, fmt);
	ft_clear_info(&info, NULL);
	while (*fmt != '\0' && ret != INVALID_NUM)
	{
		if (*fmt == '%')
		{
			fmt++;
			if (ft_parse((char **)&fmt, &ap, &info) && ft_attach(&info))
				wc = ft_putval(&info, ret);
			else
				wc = INVALID_NUM;
			ft_clear_info(&info, free);
		}
		else
			wc = ft_put2per((char **)&fmt);
		ret = ft_add_write_count(ret, wc);
	}
	va_end(ap);
	return (ret);
}

static int	ft_put2per(char **s)
{
	ssize_t	ret;
	size_t	len;

	len = 0;
	while ((*s)[len] != '\0' && (*s)[len] != '%')
		len++;
	if ((size_t)INT_MAX < len)
		return (-1);
	ret = write(1, *s, len);
	if (ret != -1)
		*s += ret;
	return ((int)ret);
}

static int	ft_putval(t_printf *info, int wc)
{
	size_t	len;

	len = info->length;
	if ((size_t)INT_MAX - len < (size_t)wc)
		return (-1);
	write(1, info->content, len);
	return (len);
}

static int	ft_add_write_count(int current, int new)
{
	if (current < 0 || new < 0 || INT_MAX - current < new)
		return (INVALID_NUM);
	return (current + new);
}

static void	ft_clear_info(t_printf *info, void (*del)(void *))
{
	info->width = 0;
	info->prec = INIT_PREC;
	info->length = 0;
	info->spec = 0;
	info->sign = 0;
	info->is_zero = false;
	info->is_unsigned = false;
	info->sharp_flag = false;
	info->left_align = false;
	info->zero_flag = false;
	if (del != NULL)
		del(info->content);
	info->content = NULL;
}
