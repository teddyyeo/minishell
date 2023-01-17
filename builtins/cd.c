/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:54:02 by tayeo             #+#    #+#             */
/*   Updated: 2023/01/17 22:15:02 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_pwd(t_mslist *list, char *name)
{
	char	*pwd;
	char	*str;

	pwd = getcwd(NULL, 0);
	str = ft_strjoin(name, pwd);
	free(pwd);
	check_exist_add(list, str);
	free(str);
}

void	change_dir_to_path(char *path, t_mslist *list)
{
	char	*msg;

	set_pwd(list, "OLDPWD=");
	if (chdir(path) != 0)
	{
		msg = ft_strjoin("minishell: cd: ", path);
		perror(msg);
		free(msg);
		list->status = 1;
		return ;
	}
	set_pwd(list, "PWD=");
}

void	change_dir_to_oldpwd(char *path, t_mslist *list)
{
	printf("%s\n", path);
	change_dir_to_path(path, list);
}

void	change_dir_to_home(t_mslist *list)
{
	char	*path;

	path = get_env_var(list->env.envp, "HOME");
	if (path == (void *)0)
	{
		printf("minishell: no home, ~ doesn't work in minishell\n");
		list->status = 1;
		return ;
	}
	change_dir_to_path(path, list);
	free(path);
}

void	cd(t_mslist *list, char	*path)
{
	char	*current_path;

	if ((!path) || ft_strcmp(path, "~") == 0)
	{
		change_dir_to_home(list);
		return ;
	}
	else if (ft_strcmp(path, "-") == 0)
	{
		current_path = get_env_var(list->env.envp, "OLDPWD");
		if (current_path == ((void *)0))
		{
			printf("minishell: cd: no OLDPWD");
			list->status = 1;
			return ;
		}
		change_dir_to_oldpwd(current_path, list);
	}
	else
	{
		current_path = path;
		change_dir_to_path(current_path, list);
	}
}
