/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:56:34 by tayeo             #+#    #+#             */
/*   Updated: 2023/01/15 06:38:52 by tayeo            ###   ########.fr       */
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

void	sort_print_env(char **envp)
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


void export(t_mslist *list, char **args)
{
	int	i;
	char	*name;

	i = 0;
	if (args == NULL || args[0] == NULL)
	{
		sort_print_env(list->env.envp);
		return ;
	}
	while (args[i] != NULL)
	{
		name = get_name(args[i]);
		if (name == NULL)
			exit(1);
		if (check_name(name) == 0)
			printf("minishell: export: \'%s\': not a valid identifier\n", name);
		else
		{
			check_exist(list, args[i]);
		}
		if (ft_strchr(args[i], '=') != 0)
			free(name);
		i++;
	}
}

/*
** 1. if there are no arguments, print sorted env with "declare -x"
** 2. if there are arguments, check if they are valid variable names
** 3. if valid -> check if the variable name exists already -> if it does replace definiton, else add to the env list
** 4. if not valid -> say so
*/

int	check_exist(t_mslist *list, char *str)
{
	int	i;
	char *name;

	i = 0;
	char **envp = list->env.envp;
	name = get_name(str);
	while (envp[i])
	{
		if (ft_strcmp(get_name(envp[i]), name) == 0)
		{
			if (ft_strchr(str, '=') != 0)
			{
				list->env.envp[i] = str;
				return (0);
			}
		}
		else
		{
			list->env.envp = add_env(envp, str);
			return (0);
		}
		i++;
	}
	return (1);
}

/*
** 1. if name matches the envp
** 	1.1. if str has '=' then replace envp[i] with str
** 2. if name does not match envp
** 	2.1. add str to tthe bottom of the envp
*/
