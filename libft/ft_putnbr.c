/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:11:58 by tayeo             #+#    #+#             */
/*   Updated: 2022/10/15 21:38:19 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen(int nb);
static int	power(int n);

int	ft_putnbr(int nb)
{
	int		index;
	int		ret;

	index = numlen(nb);
	ret = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	else
	{
		while (index >= 0)
		{
			if (nb < 0)
			{
				nb = -nb;
				ret += ft_putchar('-');
			}
			ret += ft_putchar(((nb / power(index--)) % 10) + '0');
		}
	}
	return (ret);
}

static int	numlen(int nb)
{
	int	len;

	len = 0;
	if (nb < 0)
		nb = -nb;
	while ((nb / 10) > 0)
	{
		nb /= 10;
		len ++;
	}
	return (len);
}

static int	power(int n)
{
	int	power;
	int	index;

	power = 1;
	index = 0;
	while (index < n)
	{
		power = power * 10;
		index++;
	}
	return (power);
}
