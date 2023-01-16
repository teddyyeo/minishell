/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_free_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijeong <jijeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:22:12 by jijeong           #+#    #+#             */
/*   Updated: 2023/01/02 14:22:12 by jijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ms_free_token(t_mslist *l);
static int	ms_free_cmd_struct(t_mslist *l);
static int	ms_free_cmd(t_cmd *cmd);
static int	ms_free_redi(t_redi *redi);

int	ms_free_data(t_mslist *l)
{
	ms_free_token(l);
	if (l->cmds_list != (void *)0)
		ms_free_cmd_struct(l);
	return (0);
}

static int	ms_free_token(t_mslist *l)
{
	t_token	*current;
	t_token	*temp;

	current = l->token;
	l->token = (void *)0;
	l->token_len = 0;
	while (current)
	{
		free(current->token);
		temp = current;
		current = current->next;
		free(temp);
	}
	return (0);
}

static int	ms_free_cmd_struct(t_mslist *l)
{
	int	i;
	int	j;

	i = 0;
	while (i <= l->multicmd)
	{
		j = 0;
		while (j <= l->cmds_list[i].pipenum)
		{
			ms_free_cmd(l->cmds_list[i].cmds_set[j].command);
			ms_free_redi(l->cmds_list[i].cmds_set[j].redi);
			j += 1;
		}
		free(l->cmds_list[i].cmds_set);
		free(l->cmds_list[i].pid);
		free(l->cmds_list[i].pipe);
		i += 1;
	}
	free(l->cmds_list);
	l->cmds_list = (void *)0;
	return (0);
}

static int	ms_free_cmd(t_cmd *cmd)
{
	t_cmd	*current;
	t_cmd	*temp;

	current = cmd;
	while (current)
	{
		free(current->cmd);
		temp = current;
		current = current->next;
		free(temp);
	}
	return (0);
}

static int	ms_free_redi(t_redi *redi)
{
	t_redi	*current;
	t_redi	*temp;

	current = redi;
	while (current)
	{
		free(current->filename);
		temp = current;
		current = current->next;
		free(temp);
	}
	return (0);
}
