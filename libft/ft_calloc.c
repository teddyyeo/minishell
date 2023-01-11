/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 03:44:22 by tayeo             #+#    #+#             */
/*   Updated: 2022/05/21 01:30:55 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*addr;

	if (nmemb >= 2147483647 || size >= 2147483647)
		return (0);
	addr = malloc(nmemb * size);
	if (addr == NULL)
		return (NULL);
	ft_bzero(addr, (nmemb * size));
	return (addr);
}
