/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_8b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:46:25 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/04 01:17:14 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digit_base_8b(long long n, int base, bool is_unsigned);
char		convert_char(int n);

char	*ft_itoa_base_8b(long long n, int base, bool is_unsigned)
{
	int		i;
	int		dc;
	char	*p;

	dc = count_digit_base_8b(n, base, is_unsigned);
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
			p[dc - i] = convert_char((unsigned long long)n % base);
			n /= (unsigned long long)base;
		}
		else
		{
			p[dc - i] = convert_char(n % base);
			n /= base;
		}
	}
	return (p);
}

char	convert_char(int n)
{
	if (n < 0)
		n *= -1;
	if (10 <= n)
		n += 'a' - 10;
	else
		n += '0';
	return ((char)n);
}

static int	count_digit_base_8b(long long n, int base, bool is_unsigned)
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
			n /= (unsigned long long)base;
		else
			n /= base;
	}
	return (counter);
}
