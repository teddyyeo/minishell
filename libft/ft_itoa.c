/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:06:08 by tayeo             #+#    #+#             */
/*   Updated: 2022/05/20 21:27:02 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	absol(long int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	ft_len(long int n)
{
	int	len;

	if (n > 0)
		len = 0;
	else
		len = 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	int		sign;
	char	*c;

	if (n >= 0)
		sign = 1;
	else
		sign = -1;
	len = ft_len(n);
	c = (char *)malloc(sizeof(char) * len + 1);
	if (c == NULL)
		return (0);
	c[len] = '\0';
	len--;
	while (len >= 0)
	{
		c[len] = '0' + absol(n % 10);
		n = absol(n / 10);
		len--;
	}
	if (sign == -1)
		c[0] = '-';
	return (c);
}
