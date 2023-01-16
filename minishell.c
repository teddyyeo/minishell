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

static int	tester(t_mslist *l, char *cmdline)
{
	t_token		*token;
	static char	*codename[11] = {"nothing","heredoc","file in","file out","out cat","pipeline","or list","and list","delimeter","filename","word"};
	
	token = l->token;
	printf("%s\ntoken list\n", cmdline);
	printf("token_len : %d\n", l->token_len);
	for (int i = 0; i < l->token_len ; i++)
	{
		printf("%2d : %2d [%10s]\t%s\n", i + 1, token->code, codename[token->code], token->token);
		token = token->next;
	}
	printf("command list\n");
	if (l->cmds_list != (void *)0)
	{
		printf("multicmd : %d\n", l->multicmd);
		for (int i = 0; i <= l->multicmd ; i++)
		{
			printf("%d : %d\n", i, l->cmds_list[i].pipenum);
			for (int j = 0;j <= l->cmds_list[i].pipenum;j++)
			{
				printf("\t%d : %d\n", i, j);
				for (t_redi *tmp = l->cmds_list[i].cmds_set[j].redi; tmp ;)
				{
					if (tmp)
						printf("\t\t%d : %s\n",tmp->redi_code, tmp->filename);
					if (tmp != (void *)0)
						tmp = tmp->next;
				}
				printf("\t\t");
				for (t_cmd *tmp = l->cmds_list[i].cmds_set[j].command; tmp ;)
				{
					if (tmp)
						printf("%s ",tmp->cmd);
					if (tmp != (void *)0)
						tmp = tmp->next;
				}
				printf("\n");
			}
		}
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	char		*commandline;
	t_mslist	l;

	if (argc != 1)
		if (printf("minishell: minishell: too many arguments\n"))
			exit(1);
	l.token = (void *)0;
	ms_set_data(&l, argv, envp);
	while (1)
	{
		commandline = readline("minishell> ");
		if (!commandline)
			break ;
		add_history(commandline);
		if (!ms_parse(&l, commandline))
			ms_execute(&l, 0, 0);
		tester(&l, commandline);
		free(commandline);
		ms_free_data(&l);
	}
	return (0);
}
