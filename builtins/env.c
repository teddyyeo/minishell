/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:08:22 by tayeo             #+#    #+#             */
/*   Updated: 2023/01/17 22:51:04 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	env(t_mslist *list, char **args)
{
	int		i;
	char	**envp;

	i = 0;
	envp = list->env.envp;
	if ((args == (void *)0) || (args[0] == (void *)0))
	{
		list->status = 0;
	}
	else
	{
		printf("minishell: env: too many args\n");
		list->status = 127;
		return ;
	}
	while (envp[i] != NULL)
	{
		if (ft_strchr(envp[i], '=') != NULL)
			printf("%s\n", envp[i]);
		i++;
	}
}
