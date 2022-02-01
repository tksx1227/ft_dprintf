/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 10:30:03 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/01 23:25:05 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include "../libft/includes/libft.h"

typedef struct s_print
{
	int		wc;
	int		width;
	char	spec;
	char	*content;
	bool	sharp_flag;
	bool	space_flag;
	bool	plus_flag;
	bool	minus_flag;
	bool	zero_flag;
	bool	dot_flag;
}	t_print;

int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_printf(const char *format, ...);
char	*ft_itoa_base(long long n, int base, bool islower);

#endif
