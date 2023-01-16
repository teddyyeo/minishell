/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:54:02 by tayeo             #+#    #+#             */
/*   Updated: 2023/01/17 06:03:30 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


static void	change_dir_to_path(char *path, char **envp)
{
	char	*pwd;
	char	*error_msg;
	char	buffer[2048];

	pwd = getcwd(buffer, 2048);
	hashmap_insert("OLDPWD", pwd, envp);
	if (chdir(path) != 0 && ft_strchr(path, '>') == NULL)
	{
		perror("minishell: cd error")
		return ;
	}
	pwd = getcwd(buffer, 2048);
	hashmap_insert("PWD", pwd,envp);
}

static void	change_dir_to_oldpwd(char *path)
{
	ft_printf("%s\n", path);
	change_dir_to_path(path);
}

static void	change_dir_to_home(void)
{
	char	*path;

	path = ft_strdup(hashmap_search(g_minishell.env, "HOME"));
	if (path == NULL)
	{
		error_message("cd", NO_HOME, 1);
		free(path);
		return ;
	}
	change_dir_to_path(path);
	free(path);
}

void	cd(char	*path)
{
	char	*current_path;

	//error_status = 0;
	if ((!path) || ft_strcmp(path, "~") == 0)
	{
		change_dir_to_home();
		return ;
	}
	else if (ft_strcmp(path, "-") == 0)
	{
		current_path = ft_strdup(hashmap_search(g_minishell.env, "OLDPWD"));
		if (current_path == NULL)
		{
			perror("minishell: no OLDPWD");
			return ;
		}
		change_dir_to_oldpwd(current_path);
	}
	else
	{
		current_path = ft_strdup(path);
		change_dir_to_path(current_path);
	}
	free(current_path);
}
