/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 21:49:04 by tayeo             #+#    #+#             */
/*   Updated: 2022/07/06 15:45:26 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen(int nb);
static int	power(int n);

void	ft_putnbr_fd(int nb, int fd)
{
	int			index;
	char		numchar;
	char		minus;

	numchar = 0;
	index = numlen(nb);
	minus = '-';
	if (nb == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		while (index >= 0)
		{
			if (nb < 0)
			{
				nb = -nb;
				write(fd, &minus, 1);
			}
			numchar = ((nb / power(index)) % 10) + '0';
			write(fd, &numchar, 1);
			index--;
		}
	}
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
