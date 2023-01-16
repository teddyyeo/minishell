/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_cmdline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijeong <jijeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:22:03 by jijeong           #+#    #+#             */
/*   Updated: 2023/01/02 14:22:05 by jijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ms_parse(t_mslist *l, char *cmd)
{
	ms_tokenize(l, cmd);
	if (ms_set_token_code(l->token))
		return (1);
	if (ms_check_token_code(l->token))
		return (1);
//	if (ms_make_here_doc(l))
//		return (1);
	ms_set_command_struct(l);
	return (0);
}

int	ms_tokenize(t_mslist *l, char *cmd)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (cmd[i])
	{
		if (cmd[i] == ' ')
			i++;
		else if (ms_ismeta(cmd[i]))
			ms_get_meta_token(l, &i, &j, cmd);
		else
			ms_get_word_token(l, &i, &j, cmd);
	}
	return (0);
}

int	ms_ismeta(char c)
{
	if (c == '<' || c == '>' || c == '|' || c == '&')
		return (1);
	return (0);
}

int	ms_get_meta_token(t_mslist *l, size_t *i, size_t *j, char *cmd)
{
	char	*token;

	*j = *i;
	if (cmd[*i] == cmd[*i + 1])
		*i += 1;
	token = ft_substr(cmd, *j, *i - *j + 1);
	ms_add_token(l, token);
	*i += 1;
	return (0);
}

int	ms_get_word_token(t_mslist *l, size_t *i, size_t *j, char *cmd)
{
	char	*token;

	*j = *i;
	while (cmd[*i])
	{
		if (cmd[*i] == '\'' || cmd[*i] == '\"')
			ms_pass_quote(i, cmd, cmd[*i]);
		if (!cmd[*i + 1] || cmd[*i + 1] == ' ' || ms_ismeta(cmd[*i + 1]))
		{
			token = ft_substr(cmd, *j, *i - *j + 1);
			ms_add_token(l, token);
			*i += 1;
			break ;
		}
		*i += 1;
	}
	return (0);
}

int	ms_pass_quote(size_t *i, char *cmd, char c)
{
	while (cmd[*i])
	{
		*i += 1;
		if (cmd[*i] == c)
			return (0);
	}
	printf("minishell : i can not handle odd quote\n");
	exit(1);
	return (0);
}

int	ms_add_token(t_mslist *l, char *token)
{
	t_token	*current;

	if (!l->token)
	{
		l->token = (t_token *)malloc(sizeof(t_token) * 1);
		l->token->code = 0;
		l->token->next = (void *)0;
		l->token->token = token;
		l->token_len = 1;
		return (0);
	}
	current = l->token;
	while (current->next)
		current = current->next;
	current->next = (t_token *)malloc(sizeof(t_token) * 1);
	current = current->next;
	current->token = token;
	current->code = 0;
	current->next = (void *)0;
	l->token_len += 1;
	return (0);
}

int	ms_set_token_code(t_token *token)
{
	int	pre_code;

	pre_code = 0;
	while (token)
	{
		if (ms_check_redi_token_code(token, pre_code))
			return (1);
		if (pre_code == 1 || pre_code == 2 || pre_code == 3 || pre_code == 4)
		{
			token->code = 9;
			if (pre_code == 1)
				token->code = 8;
		}
		else if (ms_ismeta(token->token[0]))
			ms_set_meta_token_code(token);
		else
			token->code = 10;
		pre_code = token->code;
		token = token->next;
	}
	return (0);
}

int	ms_check_redi_token_code(t_token *token, int pre_code)
{
	if (0 < pre_code && pre_code < 5)
	{
		if (!(token) || (token && ms_ismeta(token->token[0])))
		{
			printf("minishell: syntax error near unexpected");
			printf(" token '%s'\n", token->token);
			return (1);
		}
	}
	return (0);
}

int	ms_check_token_code(t_token *token)
{
	int	pre_code;

	pre_code = 0;
	while (token)
	{
		if ((pre_code == 0 || (5 <= pre_code && pre_code <= 7)) && \
			(5 <= token->code && token->code <= 7))
		{
			printf("minishell: syntax error near unexpected");
			printf(" token '%s'\n", token->token);
			return (1);
		}
		pre_code = token->code;
		token = token->next;
	}
	return (0);
}

int	ms_set_meta_token_code(t_token *token)
{
	if (!ft_strncmp(token->token, "<", 2))
		token->code = 2;
	if (!ft_strncmp(token->token, ">", 2))
		token->code = 3;
	if (!ft_strncmp(token->token, "|", 2))
		token->code = 5;
	if (!ft_strncmp(token->token, "&", 2))
		token->code = 10;
	if (!ft_strncmp(token->token, "<<", 2))
		token->code = 1;
	if (!ft_strncmp(token->token, ">>", 2))
		token->code = 4;
	if (!ft_strncmp(token->token, "||", 2))
		token->code = 6;
	if (!ft_strncmp(token->token, "&&", 2))
		token->code = 7;
	return (0);
}

int	ms_set_command_struct(t_mslist *l)
{
	ms_set_command_list_struct(l);
	ms_set_command_set_struct(l);
	ms_set_redi_cmd_sets(l, 0, 0);
	return (0);
}

int	ms_set_command_list_struct(t_mslist *l)
{
	int		i;
	t_token	*tmp;

	tmp = l->token;
	i = 0;
	while (tmp)
	{
		if (tmp->code == 6 || tmp->code == 7)
			i += 1;
		tmp = tmp->next;
	}
	l->cmds_list = (t_cmds_list *)malloc(sizeof(t_cmds_list) * (i + 1));
	l->multicmd = i;
	return (0);
}

int	ms_set_command_set_struct(t_mslist *l)
{
	int		i;
	int		j;
	t_token	*tmp;

	tmp = l->token;
	i = 0;
	while (tmp)
	{
		j = 0;
		while (tmp && !(tmp->code == 6 || tmp->code == 7))
		{
			if (tmp->code == 5)
				j += 1;
			tmp = tmp->next;
		}
		ms_set_command_list(l, i, j);
		i += 1;
		if (tmp && (tmp->code == 6 || tmp->code == 7))
			tmp = tmp->next;
	}
	return (0);
}

int	ms_set_command_list(t_mslist *l, int i, int j)
{
	int	k;

	l->cmds_list[i].cmds_set = (t_cmds_set *)malloc(sizeof(t_cmds_set) \
		* (j + 1));
	k = 0;
	while (k <= j)
	{
		l->cmds_list[i].cmds_set[k].command = (void *)0;
		l->cmds_list[i].cmds_set[k].redi = (void *)0;
		l->cmds_list[i].cmds_set[k].id = k;
		k += 1;
	}
	l->cmds_list[i].pipenum = j;
	l->cmds_list[i].pid = (int *)malloc(sizeof(int) * (j * 2));
	l->cmds_list[i].pipe = (pid_t *)malloc(sizeof(pid_t) * (j + 1));
	return (0);
}

int	ms_set_redi_cmd_sets(t_mslist *l, int i, int j)
{
	t_token	*tmp;

	tmp = l->token;
	while (tmp)
	{
		if (tmp->code == 5)
			j += 1;
		else if (tmp->code == 6 || tmp->code == 7)
		{
			i += 1;
			j = 0;
		}
		else
		{
			if (tmp->code == 10)
				ms_add_cmd_list(&(l->cmds_list[i].cmds_set[j]), tmp);
			else
			{
				ms_add_redi_list(&(l->cmds_list[i].cmds_set[j]), tmp);
				tmp = tmp->next;
			}
		}
		tmp = tmp->next;
	}
	return (0);
}

int	ms_add_cmd_list(t_cmds_set *cmds, t_token *token)
{
	t_cmd	*tmp;

	tmp = cmds->command;
	if (tmp == (void *)0)
	{
		cmds->command = (t_cmd *)malloc(sizeof(t_cmd));
		cmds->command->next = (void *)0;
		cmds->command->cmd = ft_strdup(token->token);
	}
	else
	{
		while (tmp->next != (void *)0)
			tmp = tmp->next;
		tmp->next = (t_cmd *)malloc(sizeof(t_cmd));
		tmp->next->next = (void *)0;
		tmp->next->cmd = ft_strdup(token->token);
	}
	return (0);
}

int	ms_add_redi_list(t_cmds_set *cmds, t_token *token)
{
	t_redi	*tmp;

	tmp = cmds->redi;
	if (tmp == (void *)0)
	{
		cmds->redi = (t_redi *)malloc(sizeof(t_redi));
		cmds->redi->next = (void *)0;
		cmds->redi->redi_code = token->code;
		cmds->redi->filename = ft_strdup(token->next->token);
	}
	else
	{
		while (tmp->next != (void *)0)
			tmp = tmp->next;
		tmp->next = (t_redi *)malloc(sizeof(t_redi));
		tmp->next->next = (void *)0;
		tmp->next->redi_code = token->code;
		tmp->next->filename = ft_strdup(token->next->token);
	}
	return (0);
}
