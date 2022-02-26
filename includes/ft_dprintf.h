/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 10:30:03 by ttomori           #+#    #+#             */
/*   Updated: 2022/02/27 01:19:28 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DPRINTF_H
# define FT_DPRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include "libft.h"

# define INVALID_NUM -1
# define INIT_PREC -1

typedef enum e_status
{
	FAIL = 0,
	SUCCESS = 1,
}	t_status;

typedef struct s_printf
{
	int		width;
	int		prec;
	int		length;
	char	spec;
	char	*content;
	char	sign;
	bool	is_zero;
	bool	sharp_flag;
	bool	left_align;
	bool	zero_flag;
}	t_printf;

int			ft_dprintf(int fd, const char *format, ...);

// Parser
t_status	ft_parse(char **fmt, va_list *ap, t_printf *info);

// Setter
t_status	ft_set_arg(va_list *ap, t_printf *info);
t_status	ft_set_char(va_list *ap, t_printf *info);
t_status	ft_set_const_char(t_printf *info, char c);
t_status	ft_set_hex(va_list *ap, t_printf *info);
t_status	ft_set_str(va_list *ap, t_printf *info);
t_status	ft_set_ptr(va_list *ap, t_printf *info);
t_status	ft_set_int(va_list *ap, t_printf *info);
t_status	ft_set_uint(va_list *ap, t_printf *info);

// Attacher
t_status	ft_attach(t_printf *info);
t_status	ft_attach_num(t_printf *info);
t_status	ft_attach_str(t_printf *info);
t_status	ft_attach_hex(t_printf *info);
t_status	ft_attach_ptr(t_printf *info);
t_status	ft_attach_prefix_common(t_printf *info, char *prefix);
t_status	ft_attach_prec_common(t_printf *info);
t_status	ft_attach_width_with_prefix_common(t_printf *info, char *prefix);

// Utils
char		*ft_itoa_base_4bytes(int n, int base, bool is_unsigned);
char		*ft_itoa_base_8bytes(long long n, int base, bool is_unsigned);

#endif
