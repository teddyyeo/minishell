/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 06:19:48 by tayeo             #+#    #+#             */
/*   Updated: 2022/05/20 18:53:15 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	l_len;
	size_t	size;

	if (*little == 0)
		return ((char *)big);
	l_len = ft_strlen(little);
	if (ft_strlen(big) < l_len || len < l_len)
		return (0);
	if (ft_strlen(big) > len)
		size = len;
	else
		size = ft_strlen(big);
	while (size-- >= l_len)
	{
		if (ft_memcmp(big, little, l_len) == 0)
			return ((char *)big);
		big++;
	}
	return (0);
}
