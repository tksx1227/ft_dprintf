/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_b4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 00:23:10 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/04 01:17:44 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		convert_char(int n);
static int	count_digit_base_4b(int n, int base, bool is_unsigned);

char	*ft_itoa_base_4b(int n, int base, bool is_unsigned)
{
	int		i;
	int		dc;
	char	*p;

	dc = count_digit_base_4b(n, base, is_unsigned);
	p = (char *)ft_calloc(dc + 1, sizeof(char));
	if (p == NULL)
		return (NULL);
	if (n == 0 || (base == 10 && n < 0))
	{
		if (n == 0)
			p[0] = '0';
		else if (base == 10 && n < 0)
			p[0] = '-';
		dc--;
	}
	i = 0;
	while (i++ < dc)
	{
		if (is_unsigned)
		{
			p[dc - i] = convert_char((unsigned int)n % base);
			n /= (unsigned int)base;
		}
		else
		{
			p[dc - i] = convert_char(n % base);
			n /= base;
		}
	}
	return (p);
}

static int	count_digit_base_4b(int n, int base, bool is_unsigned)
{
	int	counter;

	if (n == 0)
		return (1);
	counter = 0;
	if (base == 10 && n < 0)
		counter++;
	while (n != 0)
	{
		counter++;
		if (is_unsigned)
			n /= (unsigned int)base;
		else
			n /= base;
	}
	return (counter);
}
