/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:56:34 by tayeo             #+#    #+#             */
/*   Updated: 2023/01/16 06:58:47 by tayeo            ###   ########.fr       */
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


void export(t_mslist *list, char **args)
{
	int	i;
	int	flag;
	char	*name;

	i = 0;
	flag = 0;
	if (args == NULL || args[0] == NULL)
	{
		sort_print_env(list->env.envp);
		return ;
	}
	while (args[i] != NULL)
	{
		printf("args: %s\n", args[i]);
		name = get_name(args[i], &flag);
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

void	check_exist(t_mslist *list, char *str)
{
	int	i;
	int	flag;
	char	*name;
	char	*env_var;
	i = 0;
	flag = 0;
	name = get_name(str, &flag);
	char **env = list->env.envp;
	while (list->env.envp[i])
	{
		env_var = get_name(list->env.envp[i], &flag);
		if (ft_strcmp(env_var, name) == 0)
		{
				puts("match");
			printf("%s\n", ft_strchr(str, '='));
			if (ft_strchr(str, '=') != 0)
			{
				puts("no definition");
				list->env.envp[i] = str;
				free(name);
				return ;
			}
		}
		i++;
	}
	list->env.envp = add_env(env, str);
	return ;
}

/*
** 1. if name matches the envp
** 	1.1. if str has '=' then replace envp[i] with str
** 2. if name does not match envp
** 	2.1. add str to tthe bottom of the envp
*/
