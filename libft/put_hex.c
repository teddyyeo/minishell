/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:04:12 by tayeo             #+#    #+#             */
/*   Updated: 2022/10/15 21:38:35 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nibble(unsigned long num, int index)
{
	return ((num >> (4 * index)) & 0xF);
}

static int	put_hex(unsigned long num, int type_size, char c)
{
	int	i;
	int	ret;

	i = 2 * type_size - 1;
	ret = 0;
	while (nibble(num, i) == 0)
		i--;
	while (i >= 0)
		ret += ft_putchar("0123456789ABCDEF"[nibble(num, i--)] | (c - 'X'));
	return (ret);
}

int	put_hex_int(int num, char c)
{
	return (put_hex(num, sizeof(int), c));
}

int	put_hex_addr(void *addr)
{
	unsigned long	num_addr;

	if (addr == NULL)
		return (write(1, "(null)", 6));
	else
	{
		ft_printf("0x");
		num_addr = (unsigned long)addr;
		return (put_hex(num_addr, sizeof(unsigned long), 'x') + 2);
	}
}
