/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 22:22:52 by tayeo             #+#    #+#             */
/*   Updated: 2022/05/21 01:24:03 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isinset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*new;

	if (s1 == NULL || set == 0)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	while (s1[i] && ft_isinset(s1[i], set))
		i++;
	while (j > i && ft_isinset(s1[j - 1], set))
		j--;
	new = malloc(sizeof(char) * (j - i + 1));
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, s1 + i, j - i + 1);
	return (new);
}	
