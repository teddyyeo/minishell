/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 21:47:18 by tayeo             #+#    #+#             */
/*   Updated: 2022/05/20 21:47:25 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		l1;
	int		l2;
	char	*new;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	new = malloc(sizeof(char) * (1 + l1 + l2));
	if (new == NULL)
		return (NULL);
	ft_memmove(new, s1, l1);
	ft_memmove(new + l1, s2, l2);
	*(new + l1 + l2) = '\0';
	return (new);
}
