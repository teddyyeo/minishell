/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 21:45:45 by tayeo             #+#    #+#             */
/*   Updated: 2023/01/17 22:41:11 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoi(const char *str)
{
	int			sign;
	long long	num;

	num = 0;
	sign = 1;
	while ((*str > 8 && *str < 14) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		sign *= (44 - *str);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num *= 10;
		num += *str - 48;
		str++;
	}
	num *= sign;
	return (num);
}
