/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_uint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:33:37 by tayeo             #+#    #+#             */
/*   Updated: 2022/10/15 21:38:40 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			numlen(unsigned int nb);
static unsigned int	power(unsigned int n);

int	put_uint(unsigned int num)
{
	int			index;
	char		numchar;

	numchar = 0;
	index = numlen(num);
	while (index >= 0)
	{
		numchar = ((num / power(index)) % 10) + '0';
		write(1, &numchar, 1);
		index--;
	}
	return (numlen(num) + 1);
}

static int	numlen(unsigned int nb)
{
	int	len;

	len = 0;
	while ((nb / 10) > 0)
	{
		nb /= 10;
		len ++;
	}
	return (len);
}

static unsigned int	power(unsigned int n)
{
	unsigned int	power;
	unsigned int	index;

	power = 1;
	index = 0;
	while (index < n)
	{
		power = power * 10;
		index++;
	}
	return (power);
}
