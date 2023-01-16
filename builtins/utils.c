/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 21:30:25 by tayeo             #+#    #+#             */
/*   Updated: 2023/01/16 20:31:09 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**dupe_env(char **envp)
{
	char	**dupe;
	int		i;

	i = 0;
	while (envp[i])
		i++;
	dupe = (char **)malloc(sizeof(char *) * (i + 1));
	if (!dupe)
		return ((void *)0);
	dupe[i] = 0;
	while (i > 0)
	{
		i--;
		dupe[i] = ft_strdup(envp[i]);
		if (dupe[i] == (void *)0)
			return ((void *)0);
	}
	return (dupe);
}

void	free_double_ptr(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i] != (void *)0)
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

void	free_ptr(char *ptr, int *flag)
{
	if (*flag == 1 && ptr != (void *)0)
	{
		*flag = 0;
		free(ptr);
		ptr = (void *)0;
	}
}

int	get_env_num(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		i++;
	return (i);
}
