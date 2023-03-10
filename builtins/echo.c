/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:57:15 by tayeo             #+#    #+#             */
/*   Updated: 2023/01/17 19:30:40 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	echo(t_mslist *list, char **argv)
{
	int	i;

	i = 0;
	list->status = 0;
	if (ft_strncmp(argv[0], "-n", 2) == 0)
		i++;
	while (argv[i] != 0)
	{
		printf("%s", argv[i]);
		i++;
	}
	if (ft_strncmp(argv[0], "-n", 2) != 0)
		printf("\n");
}
