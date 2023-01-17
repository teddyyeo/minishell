/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:55:42 by tayeo             #+#    #+#             */
/*   Updated: 2023/01/17 22:31:25 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	pwd(t_mslist *list)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	list->status = 0;
	if (cwd == NULL)
		perror("minishell: getcwd() error");
	else
	{
		printf("%s\n", cwd);
		free(cwd);
	}
	exit(0);
}
