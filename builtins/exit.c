/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 05:49:50 by tayeo             #+#    #+#             */
/*   Updated: 2023/01/17 22:59:16 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_numeric(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (!ft_isdigit(string[i]))
			return (0);
		i++;
	}
	return (1);
}

void	check_first_arg(t_mslist *list, char *arg)
{
	if (!check_numeric(arg))
	{
		list->status = 255;
		printf("minishell: exit: %s: numeric argument required\n", arg);
		exit(list->status);
	}
	list -> status = (ft_atoi(arg) % 256);
}

void	exit_builtin(t_mslist *list, char **argv)
{
	list->status = 0;
	if (argv == NULL || argv[0] == NULL)
	{
		printf("exit\n");
		exit(list->status);
	}
	check_first_arg(list, argv[0]);
	if (get_env_num(argv) > 1)
	{
		list->status = 1;
		printf("minishell: exit: too many arguments\n");
		exit(list->status);
	}
	printf("exit\n");
	exit(list->status);
}
