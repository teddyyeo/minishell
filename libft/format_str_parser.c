/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_str_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:34:31 by tayeo             #+#    #+#             */
/*   Updated: 2022/10/15 21:48:14 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	format_str_parser(va_list arg_ptr, char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(arg_ptr, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(arg_ptr, char *)));
	else if (format == 'p')
		return (put_hex_addr(va_arg(arg_ptr, void *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(arg_ptr, int)));
	else if (format == 'u')
		return (put_uint(va_arg(arg_ptr, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (put_hex_int(va_arg(arg_ptr, int), format));
	else if (format == '%')
		return (ft_putchar('%'));
	return (0);
}
