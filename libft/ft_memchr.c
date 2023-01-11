/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 04:05:55 by tayeo             #+#    #+#             */
/*   Updated: 2022/05/20 20:03:06 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*temp;

	temp = s;
	while (n && *temp != (unsigned char)c)
	{
		temp++;
		n--;
	}
	if (n)
		return ((void *)(temp));
	return (NULL);
}
