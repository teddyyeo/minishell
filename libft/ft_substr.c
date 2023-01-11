/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 22:11:43 by tayeo             #+#    #+#             */
/*   Updated: 2022/05/21 01:23:18 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ss;
	unsigned int	i1;
	unsigned int	i2;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	ss = (char *)malloc(sizeof(char) * (len + 1));
	i1 = 0;
	i2 = 0;
	if (ss == NULL)
		return (NULL);
	while (s[i1])
	{
		if (i1 >= start && i2 < len)
		{
			ss[i2++] = s[i1];
		}
		i1++;
	}
	ss[i2] = '\0';
	return (ss);
}
