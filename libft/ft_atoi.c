/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 21:45:45 by tayeo             #+#    #+#             */
/*   Updated: 2022/05/20 21:45:56 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	num;

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
