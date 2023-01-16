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

int	ms_execute(t_mslist *l, int cnt_list, int cnt_cmd)
{
	char	*cmd = "/bin/ls";
	char	**cmds = (void *)0;
	int		res;

	while (cnt_list <= l->multicmd)
	{
		cnt_cmd = 0;
		while (cnt_cmd <= l->cmds_list[cnt_list].pipenum)
		{
			l->cmds_list[cnt_list].pid[cnt_cmd] = fork();
			if (l->cmds_list[cnt_list].pid[cnt_cmd] == 0)
			{
				ms_set_redirection(l, cnt_list, cnt_cmd);
//				cmds = ms_get_cmds(l->cmds_list[cnt_list].cmds_set[cnt_cmd], l->env.envp);
//				cmd = ms_get_cmd(cmds[0], l->env.envp);
//				if (ms_check_builtin(l))
//					res = ms_builtin_cmd(cmd, cmds, l->env.envp);
//				else
					res = execve(cmd, cmds, l->env.envp);
				exit(res);
			}
			cnt_cmd += 1;
		}
		waiting_child(l, cnt_list);
		cnt_list += 1;
	}
	return (0);
}

int	ms_set_redirection(t_mslist *l, int cnt_list, int cnt_cmd)
{
	t_redi	*tmp;

	ms_set_pipe_fd(l, cnt_list, cnt_cmd);
	tmp = l->cmds_list[cnt_list].cmds_set[cnt_cmd].redi;
	while (tmp)
	{
		if (tmp->redi_code < 3)
			open(tmp->filename, O_RDONLY);
		else
			open(tmp->filename, O_TRUNC | O_CREAT | O_WRONLY, 0644);
		tmp = tmp->next;
	}
	return (0);
}

int	ms_set_pipe_fd(t_mslist *l, int cnt_list, int cnt_cmd)
{
	int	i;
	int	n;

	i = 0;
	n = l->cmds_list[cnt_list].pipenum;
	while (i <= n)
	{
		if (i == cnt_cmd)
		{
			if (i != 0)
				dup2(2 * (i - 1), STDIN_FILENO);
			if (i != n)
				dup2((2 * i) + 1, STDOUT_FILENO);
		}
		else
		{
			if (i != 0)
				close(2 * (i - 1));
			if (i != n)
				close((2 * i) + 1);
		}
		i += 1;
	}
	return (0);
}

int	waiting_child(t_mslist *l, int cnt_list)
{
	int	i;
	int	status;

	i = 0;
	while (i <= l->cmds_list[cnt_list].pipenum)
	{
		waitpid(l->cmds_list[cnt_list].pid[i], &status, 0);
		i += 1;
	}
	l->status = status % 256;
	return (0);
}
