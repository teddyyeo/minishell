/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijeong <jijeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:06:03 by jijeong           #+#    #+#             */
/*   Updated: 2023/01/16 13:06:19 by jijeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ms_make_here_doc(t_mslist *l)
{
	t_token	*tmp;
	char	*line;
	char	*delimiter;
	int		quote;
	int		fd;

	tmp = l->token;
	while (tmp)
	{
		quote = 0;
		if (tmp->code == 8)
		{
			ms_make_temp_file(tmp, &fd);
			ms_get_delimiter(tmp->token, &quote);
			while (1)
			{
				line = readline("> ");
				if (!line)
					exit(1);
				if (ft_strncmp(delimiter, line, ft_strlen(delimiter)))
					break ;
				if (quote)
					line = ms_parse_str(l, line, 0);
				write(fd, line, ft_strlen(line));
			}
		}
		tmp = tmp->next;
	}
	return (0);
}

int	ms_make_temp_file();