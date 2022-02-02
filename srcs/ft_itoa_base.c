/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:46:25 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/03 02:13:23 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digit_base(long long n, int base);
static void	convert_base(char *p, long long n, int base, bool islower);

char	*ft_itoa_base(long long n, int base, bool islower)
{
	int		dc;
	char	*p;
	char	*head;

	if (base != 10)
		n = (unsigned long long)n;
	dc = count_digit_base(n, base);
	p = (char *)malloc(sizeof(char) * (dc + 1));
	if (p == NULL)
		return (NULL);
	head = p;
	p[dc] = '\0';
	if (n < 0)
	{
		n *= -1;
		*p++ = '-';
	}
	else if (n == 0)
		*p++ = '0';
	convert_base(head + dc - 1, n, base, islower);
	return (head);
}

static void	convert_base(char *s, long long n, int base, bool islower)
{
	int	c;

	if (n == 0)
		return ;
	convert_base(s - 1, n / base, base, islower);
	c = n % base;
	if (10 <= c)
	{
		if (islower)
			c += 'a' - 10;
		else
			c += 'A' - 10;
	}
	else
	{
		c += '0';
	}
	*s = (char)c;
}

static int	count_digit_base(long long n, int base)
{
	int	counter;

	counter = 0;
	if (n == 0)
		counter++;
	else if (n < 0)
		counter++;
	while (n != 0)
	{
		counter++;
		n /= base;
	}
	return (counter);
}
