/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 21:30:25 by tayeo             #+#    #+#             */
/*   Updated: 2023/01/14 15:24:21 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_double_ptr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while ((*s1 && *s2) && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

char *get_name(char *str)
{
	int		i;
	int		len;
	char	*var_name;

	i = 0;
	len = ft_strlen(str);
	if (ft_strchr(str, '=') != NULL)
	{
		*ft_strchr(str, '=') = 0;
		var_name = ft_strdup(str);
		return (var_name);
	}
	return (str);
}

int	check_name(char *str)
{
	int	i;

	i = 0;
	if (ft_isdigit(str[0]))
		return (0);
	while (str[i] != 0)
	{
		if (!ft_isalnum(str[i]) || str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

