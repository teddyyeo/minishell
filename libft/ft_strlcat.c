/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 05:27:04 by tayeo             #+#    #+#             */
/*   Updated: 2022/05/20 18:48:29 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *d, const char *s, size_t n)
{
	if (ft_strlen(d) >= n)
		return (n + ft_strlen(s));
	return (ft_strlen(d) + ft_strlcpy(d + ft_strlen(d), s, n - ft_strlen(d)));
}
