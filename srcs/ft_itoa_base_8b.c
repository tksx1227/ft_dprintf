/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_8b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:46:25 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/06 13:18:53 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digit_base_8b(t_ll n, int base, bool is_unsigned);
static void	set_char_8b(char *p, t_ll n, int base, bool is_unsigned);

char	*ft_itoa_base_8b(t_ll n, int base, bool is_unsigned)
{
	int		dc;
	char	*p;

	dc = count_digit_base_8b(n, base, is_unsigned);
	p = (char *)ft_calloc(dc + 1, sizeof(char));
	if (p == NULL)
		return (NULL);
	if (n == 0)
		*p = '0';
	else if (!is_unsigned && base == 10 && n < 0)
		*p = '-';
	set_char_8b(p + dc - 1, n, base, is_unsigned);
	return (p);
}

static int	count_digit_base_8b(t_ll n, int base, bool is_unsigned)
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
			n /= (t_ull)base;
		else
			n /= base;
	}
	return (counter);
}

static void	set_char_8b(char *p, t_ll n, int base, bool is_unsigned)
{
	char	c;

	while (n != 0)
	{
		if (is_unsigned)
			c = (t_ull)n % base;
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
			n /= (t_ull)base;
		else
			n /= base;
	}
}
