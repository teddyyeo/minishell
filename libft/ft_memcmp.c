/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 04:15:52 by tayeo             #+#    #+#             */
/*   Updated: 2022/05/20 18:36:43 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*temp1;
	const unsigned char	*temp2;

	temp1 = s1;
	temp2 = s2;
	while (n && *temp1 == *temp2)
	{
		temp1++;
		temp2++;
		n--;
	}
	if (n)
		return (*temp1 - *temp2);
	return (0);
}
