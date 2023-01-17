/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:56:34 by tayeo             #+#    #+#             */
/*   Updated: 2023/01/17 22:47:43 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

/*
** 1. if there are no arguments, print sorted env with "declare -x"
** 2. if there are arguments, check if they are valid variable names
** 3. if valid -> check if it exists already -> if it does replace definiton,
**     else add to the env list
** 4. if not valid -> say so
*/
void	export(t_mslist *list, char **args)
{
	int		i;
	int		flag;
	char	*name;

	i = 0;
	flag = 0;
	list->status = 0;
	if (args == (void *)0 || args[0] == (void *)0)
	{
		sort_print_env(list->env.envp);
		exit(list->status);
	}
	while (args[i] != (void *)0)
	{
		name = get_name(args[i], &flag);
		if (!export_error(args[i], name, list))
			check_exist_add(list, args[i]);
		free_ptr(name, &flag);
		i++;
	}
	exit(list->status);
}

void	check_exist_add(t_mslist *list, char *str)
{
	int		i;
	int		flag[2];
	char	*name;
	char	*env_var;

	i = 0;
	name = get_name(str, &flag[0]);
	while (list->env.envp[i])
	{
		env_var = get_name(list->env.envp[i], &flag[1]);
		if (ft_strcmp(env_var, name) == 0)
		{
			update(list, str, i);
			free_ptr(env_var, &flag[1]);
			free_ptr(name, &flag[0]);
			return ;
		}
		free_ptr(env_var, &flag[1]);
		i++;
	}
	list->env.envp = add_env(list->env.envp, str);
	free_ptr(name, &flag[0]);
	return ;
}

void	update(t_mslist *list, char *str, int i)
{
	if (ft_strchr(str, '=') != (void *)0)
	{
		free(list->env.envp[i]);
		list->env.envp[i] = ft_strdup(str);
	}
}

int	export_error(char *str, char *name, t_mslist *list)
{
	if (str[0] == '=')
	{
		printf("minishell: export: \'%s\': not a valid identifier", str);
		list->status = 1;
		return (1);
	}
	if (!check_name(name))
	{
		printf("minishell: export: \'%s\': not a valid identifier", name);
		list->status = 1;
		return (1);
	}
	return (0);
}
/*
** 1. if name matches the envp
** 	1.1. if str has '=' then replace envp[i] with str
** 2. if name does not match envp
** 	2.1. add str to tthe bottom of the envp
*/
