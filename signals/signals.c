/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 23:08:08 by tayeo             #+#    #+#             */
/*   Updated: 2023/01/17 23:15:33 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

void	sig_handler(int signum)
{
	if (signum == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	signaling(void)
{
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
}
