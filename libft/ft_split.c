/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 21:48:07 by tayeo             #+#    #+#             */
/*   Updated: 2022/05/20 22:30:12 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	num(char const *str, char c)
{
	char	prev;
	int		count;

	count = 0;
	prev = 0;
	if (*str == 0)
		return (0);
	while (1)
	{
		if (*str == c && prev != c && prev != 0)
			count++;
		else if ((*str == 0) && (prev != c))
			count++;
		if (*str == 0)
			break ;
		prev = *str;
		str++;
	}
	return (count);
}

int	slen(char const *str, char c)
{
	int	len;

	len = 0;
	while ((str[len] != c) && str[len] != 0)
		len++;
	return (len);
}

char	*ft_strncpy(char *dest, char const *src, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	**ft_fail_malloc(char **str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *str, char c)
{
	char	**superstring;
	int		i;
	int		len;
	int		n;

	n = num(str, c);
	superstring = malloc(sizeof(char *) * (n + 1));
	if (superstring == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		len = slen(str, c);
		if (len != 0)
		{
			superstring[i] = malloc((len + 1) * sizeof(char));
			if (superstring[i] == 0)
				return (ft_fail_malloc(superstring));
			ft_strncpy(superstring[i++], str, len);
		}
		str += len + 1;
	}
	superstring[i] = 0;
	return (superstring);
}
