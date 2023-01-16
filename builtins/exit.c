/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 05:49:50 by tayeo             #+#    #+#             */
/*   Updated: 2023/01/17 06:03:32 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	is_string_number(char *string)
{
	while (*string)
		if (!ft_isdigit(*string++))
			return (0);
	return (1);
}

static void	parse_first_arg(char *arg)
{
	if (!arg)
		return ;
	g_minishell.error_status = ft_atoi(arg);
	if (is_string_number(arg))
		return ;
	perror("minishll: nonnumric arguments");
	exit_minishell();
}

void	exit_builtin(char **argv)
{
	int	argc;

	parse_first_arg(*(argv + 1));
	if (get_env_num(argv) > 1)
	{
		perror("minishell: too many arguments");
		return ;
	}
	ft_printf("exit\n");
	exit_minishell();
}
