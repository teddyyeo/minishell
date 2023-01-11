/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:09:44 by tayeo             #+#    #+#             */
/*   Updated: 2022/10/15 21:48:31 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	gnl_ft_strlen(const char *s)
{
	const char	*start;

	start = s;
	if (s == NULL)
		return (0);
	while (*s)
		s++;
	return (s - start);
}

char	*gnl_ft_strjoin(char const *s1, char const *s2, int flag)
{
	int		l1;
	int		l2;
	char	*new;

	l1 = gnl_ft_strlen(s1);
	l2 = gnl_ft_strlen(s2);
	new = malloc(sizeof(char) * (1 + l1 + l2));
	if (new == NULL)
		return (NULL);
	if (s1 != NULL)
		gnl_ft_memmove(new, s1, l1);
	gnl_ft_memmove(new + l1, s2, l2);
	*(new + l1 + l2) = '\0';
	if (flag == 1 && s1 != NULL)
		free((void *)s1);
	return (new);
}

void	*gnl_ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)src;
	if (dest == src || src == NULL)
		return (dest);
	if (s < d)
	{
		while (n--)
			*(d + n) = *(s + n);
		return (dest);
	}
	while (n--)
		*d++ = *s++;
	return (dest);
}

char	*gnl_ft_strchr(const char *s, int c)
{
	while (*s && *s != (unsigned char)c)
		s++;
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}
