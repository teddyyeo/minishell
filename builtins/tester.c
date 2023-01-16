/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:18:01 by tayeo             #+#    #+#             */
/*   Updated: 2023/01/16 20:18:09 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_mslist	list;

	list.env.envp = dupe_env(envp);
	printf("arg num: %d\n", argc);
	export(&list, &argv[1]);
	printf("\n\n\n\n\n");
	export(&list, (void *)0);
	printf("\n\n\n\n\n");
	env(list.env.envp);
	free(list.env.envp);
}
