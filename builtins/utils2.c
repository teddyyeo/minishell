/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:08:23 by tayeo             #+#    #+#             */
/*   Updated: 2023/01/17 22:50:03 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	error_ctl(int flag, char *msg, int status, t_mslist *list)
{
	if (flag == 1)
	{
		printf("error: %s\n", msg);
		list->status = status;
	}
}

void	malloc_error_handler(void *ptr)
{
	if (ptr == (void *)0)
	{
		perror("minishell: malloc failed");
		exit(1);
	}
}

char	*get_env_var(char **envp, char *str)
{
	int		i;
	char	*name[2];
	int		flag[2];

	i = 0;
	name[0] = get_name(str, &flag[0]);
	while (envp[i])
	{
		name[1] = get_name(envp[i], &flag[1]);
		if (ft_strcmp(name[0], name[1]) == 0)
		{
			free_ptr(name[0], &flag[0]);
			free_ptr(name[1], &flag[1]);
			return (envp[i]);
		}
		free_ptr(name[1], &flag[1]);
		i++;
	}
	free_ptr(name[0], &flag[0]);
	return ((void *)0);
}
