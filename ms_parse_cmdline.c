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
	ms_token_interpreter(l->token);
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
		if (pre_code == 1 || pre_code == 2 || pre_code == 3 || pre_code == 4)
		{
			if (ms_ismeta(token->token[0]))
			{
				printf("minishell: syntax error near unexpected");
				printf(" token '%s'\n", token->token);
				return (1);
			}
			token->code = 8;
		}
		else if (ms_ismeta(token->token[0]))
			ms_set_meta_token_code(token);
		else
			token->code = 9;
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
	{
		printf("minishell : i can not handle &\n");
		exit(1);
	}
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

int	ms_token_interpreter(t_token *token)
{
	while (token)
	{
		if (token->code == 8 || token->code == 9)
		{
			if (token->code == 8)
				ms_check_ambiguous_redirect(token->token);
//			ms_parameter_expansion();
//			ms_word_splitting();
//			ms_globbing();
//			ms_remove_quote_and_cat();
		}
		token = token->next;
	}
	return (0);
}

int	ms_check_ambiguous_redirect(char *str)
{
	size_t	i;
	char	*key;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			ms_pass_quote(&i, str, str[i]);
		if (str[i] == '$' && ms_isverable(str[i + 1]))
		{
			key = ms_get_key(&str[i + 1]);
			printf("minishell: $%s: ambicuous redirect\n", key);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ms_isverable(char c)
{
	if (c == '_')
		return (1);
	return (ft_isalpha((int)c));
}

char	*ms_get_key(char *str)
{
	int	i;

	i = 0;
	while(ms_isverable(str[i]))
		i++;
	return (ft_substr(str, 0, i));
}
