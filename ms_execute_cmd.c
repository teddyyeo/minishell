/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijeong <jijeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:22:07 by jijeong           #+#    #+#             */
/*   Updated: 2023/01/02 14:22:08 by jijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ms_execute(t_mslist *l)
{
	int		cmds_set_n;
	int		cmds_n;
	int		*pipes;
	char	cmd;

	cmds_set_n = 0;
	while (cmds_set_n <= l->multicmd)
	{
		pipes = (int *)malloc(sizeof(int) * l->cmds_sets->pipenum * 2);
		cmds_n = 0;
		while (cmds_n <= l->cmds_sets[cmds_set_n].pipenum)
		{
			l->cmds_sets[cmds_set_n].cmds_set->pid = fork();
			ms_redirection(l);
			if (ms_check_builtin())
				ms_builtin_cmd();
			else
			{
				cmd = ms_get_command(l->cmds_sets[cmds_set_n]);
				execve(cmd, l->cmds_sets[cmds_n].cmds_set->cmds, l->env.envp);
			}
		}
		waiting_child();
		free(cmd);
		ms_free_pipe(pipes, l->cmds_sets->pipenum);
		cmds_set_n += 1;
	}
}
