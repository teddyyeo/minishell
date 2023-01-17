/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 06:47:18 by tayeo             #+#    #+#             */
/*   Updated: 2023/01/17 22:50:19 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
** 1. if no args -> do nothing(return 1)
** 2. if variable name is not valid -> print error
** 3. if variable name is valid -> check for match in envp
** 4. if there is a match, remove the variable from envp
*/
int	unset(t_mslist *list, char **args)
{
	int	i;

	i = 0;
	list->status = 0;
	if (args == NULL)
		return (0);
	while (args[i])
	{
		if (check_name(args[i]) == 0)
		{
			printf("minishell: unset: not a valid identifier \'%s\'\n",
				args[i]);
			list->status = 1;
		}
		else
		{
			if (check_match(list->env.envp, args[i]) == 1)
				list->env.envp = remove_env(list, args[i]);
		}
		i++;
	}
	return (list->status);
}

int	check_match(char **envp, char *str)
{
	int		i;
	int		flag[2];
	char	*name;
	char	*env_var;

	i = 0;
	name = get_name(str, &flag[0]);
	while (envp[i])
	{
		env_var = get_name(envp[i], &flag[1]);
		if (ft_strcmp(env_var, name) == 0)
		{
			free_ptr(env_var, &flag[1]);
			free_ptr(name, &flag[0]);
			return (1);
		}
		free_ptr(env_var, &flag[1]);
		i++;
	}
	free_ptr(name, &flag[0]);
	return (0);
}

char	**remove_env(t_mslist *list, char *var_name)
{
	char	**dupe;
	int		idx[2];
	int		env_num;
	char	*str;
	int		flag;

	idx[0] = 0;
	env_num = get_env_num(list->env.envp);
	dupe = (char **)malloc(sizeof(char *) * (env_num));
	malloc_error_handler((void *)dupe);
	dupe[env_num - 1] = 0;
	while (idx[0] < env_num - 1)
	{
		str = get_name(list->env.envp[idx[1]], &flag);
		if (ft_strcmp(var_name, str) != 0)
		{
			dupe[idx[0]] = ft_strdup(list->env.envp[idx[1]]);
			idx[0]++;
		}
		free_ptr(str, &flag);
		idx[1]++;
	}
	free_double_ptr(list->env.envp);
	return (dupe);
}
