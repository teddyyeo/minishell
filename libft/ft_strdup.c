/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 05:20:03 by tayeo             #+#    #+#             */
/*   Updated: 2022/05/20 18:42:54 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	l;
	char	*d;

	l = ft_strlen(s);
	d = malloc(l + 1);
	if (!d)
		return (NULL);
	return (ft_memcpy(d, s, l + 1));
}
