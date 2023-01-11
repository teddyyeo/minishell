/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:32:08 by tayeo             #+#    #+#             */
/*   Updated: 2022/10/15 21:38:11 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	int		ret;
	va_list	arg_ptr;

	ret = 0;
	va_start(arg_ptr, format);
	while (*format)
	{
		if (*format != '%')
			ret += ft_putchar(*format);
		else
			ret += format_str_parser(arg_ptr, *(++format));
		format++;
	}
	va_end(arg_ptr);
	return (ret);
}
