/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:56:34 by tayeo             #+#    #+#             */
/*   Updated: 2023/01/14 16:48:46 by tayeo            ###   ########.fr       */
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

void export(char **argv, char **envp)
{
	int	i;
	char	*name;

	i = 0;
	if (argv[0] == NULL)
	{
		sort_print_env(envp);
		return ;
	}
	while (argv[i] != NULL)
	{
		name = get_name(argv[i]);
		if (name == NULL)
			exit(1);
		if (check_name(name) == 0)
			printf("minishell: export: \'%s\': not a valid identifier\n", name);
		else
		{
			//check_exist(envp, argv[i]);
		}
		if (ft_strchr(argv[i], '=') != 0)
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
/*
int	check_exist(char **envp, char *str)
{
	int	i;
	char *name;

	i = 0;
	name = get_name(str);
	while (envp[i])
	{
		if (ft_strcmp(get_name(envp[i]), name) == 0)

		i++;
	}
}*/
