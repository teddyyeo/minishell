/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:56:34 by tayeo             #+#    #+#             */
/*   Updated: 2023/01/11 21:36:41 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	**dupe_env(char **envp)
{
	char	**dupe;
	int	i;

	while (envp[i])
		i++;
	dupe = (char **)malloc(sizeof(char *) * (i + 1));
	if (!dupe)
		return (NULL);
	dupe[i] = 0;
	while (i > 0)
	{
		i--;
		dupe[i] = ft_strdup(envp[i]);
	}
	return (dupe);
}

void	print_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		printf("declare -x %s\n", envp[i]);
		i++;
	}
}

void	sort_env(char **envp)
{
	char	**dup;
	char	*tmp;
	size_t	i;
	size_t	j;

	dup = dupe_env(envp);
	i = 0;
	while (dup[i])
	{
		j = i + 1;
		while (dup[j])
		{
			if (ft_strcmp(dup[i], dup[j]) > 0)
			{
				tmp = dup[i];
				dup[i] = dup[j];
				dup[j] = tmp;
			}
			j++;
		}
		i++;
	}
	print_env(dup);
	free_double_ptr(dup);
}

void export(char **argv, char **envp)
{
	if (argv == 0)
		sort_env(envp);
}

int	check_var_name(char *str)
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
