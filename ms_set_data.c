/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_set_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijeong <jijeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:21:57 by jijeong           #+#    #+#             */
/*   Updated: 2023/01/02 14:22:02 by jijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ms_set_data(t_mslist *l, char **argv, char **envp)
{
	(void)argv;
	l->cmds_list = (void *)0;
	l->env.envp = envp;
	l->multicmd = 0;
	l->status = 0;
	l->token = (void *)0;
	l->token_len = 0;
	return (0);
}
