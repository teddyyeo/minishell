/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 21:30:25 by tayeo             #+#    #+#             */
/*   Updated: 2023/01/16 06:42:57 by tayeo            ###   ########.fr       */
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
	printf("number of envs: %d\n", i);
	dupe = (char **)malloc(sizeof(char *) * (i + 1));
	if (!dupe)
		return (NULL);
	dupe[i] = 0;
	while (i > 0)
	{
		i--;
		dupe[i] = ft_strdup(envp[i]);
		if (dupe[i] == NULL)
			return(NULL);
	}
	return (dupe);
}

void	free_double_ptr(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
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

void	free_ptr(char *ptr, int *flag)
{
	if (*flag == 1 && ptr != NULL)
	{
		*flag = 0;
		free(ptr);
		ptr = NULL;
	}
}
