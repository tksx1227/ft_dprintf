/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_4bytes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 00:23:10 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/06 13:24:52 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digit_base_4bytes(int n, int base, bool is_unsigned);
static void	set_char_4bytes(char *p, int n, int base, bool is_unsigned);

char	*ft_itoa_base_4bytes(int n, int base, bool is_unsigned)
{
	int		dc;
	char	*p;

	dc = count_digit_base_4bytes(n, base, is_unsigned);
	p = (char *)ft_calloc(dc + 1, sizeof(char));
	if (p == NULL)
		return (NULL);
	if (n == 0)
		*p = '0';
	else if (!is_unsigned && base == 10 && n < 0)
		*p = '-';
	set_char_4bytes(p + dc - 1, n, base, is_unsigned);
	return (p);
}

static int	count_digit_base_4bytes(int n, int base, bool is_unsigned)
{
	int	counter;

	if (n == 0)
		return (1);
	counter = 0;
	if (!is_unsigned && base == 10 && n < 0)
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

static void	set_char_4bytes(char *p, int n, int base, bool is_unsigned)
{
	char	c;

	while (n != 0)
	{
		if (is_unsigned)
			c = (unsigned int)n % base;
		else
			c = n % base;
		if (c < 0)
			c *= -1;
		if (10 <= c)
			c += 'a' - 10;
		else
			c += '0';
		*p-- = c;
		if (is_unsigned)
			n /= (unsigned int)base;
		else
			n /= base;
	}
}
