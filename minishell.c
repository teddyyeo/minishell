/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijeong <jijeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:38:23 by jijeong           #+#    #+#             */
/*   Updated: 2023/01/02 13:42:41 by jijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char		*commandline;
	t_mslist	l;

	if (argc != 1)
		if (printf("minishell: minishell: too many arguments\n"))
			exit(1);
	printf("%d %s %s\n",argc, argv[0], envp[0]);
	l.token = (void *)0;
//	ms_set_data(&l, argv, envp);
	while (1)
	{
		commandline = readline("minishell> ");
		if (!commandline)
			break ;
		if (commandline[0] == '\0')
			printf("hello world\n\n");
		add_history(commandline);
		if (!ms_parse(&l, commandline))
		{
//			ms_set_command_struct(&l);
//			ms_execute(&l);
		}
		free(commandline);
//		ms_free_data(&l, commandline);
		t_token *token = l.token;
		char	*codename[10] = {"nothing","heredoc","file in","file out","out cat","pipeline","or list","and list","filename","word"};
		printf("token_len : %d\n", l.token_len);
		for (int i = 0; i < l.token_len ; i++)
		{
			printf("%2d : %d [%10s]\t%s\n", i + 1, token->code, codename[token->code], token->token);
			token = token->next;
		}
		ms_free_token(&l);
	}
	return (0);
}

int	ms_free_token(t_mslist *l)
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
