/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:12:07 by tayeo             #+#    #+#             */
/*   Updated: 2022/10/15 21:51:39 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	ssize_t		read_bytes;
	static char	*safe;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	while (1)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes < 0)
			return (NULL);
		buf[read_bytes] = '\0';
		safe = gnl_ft_strjoin(safe, buf, 1);
		if (gnl_ft_strchr(safe, '\n'))
			return (saver(&safe));
		if (read_bytes == 0)
			return (end_of_file(&safe));
	}
}

char	*saver(char **safe)
{
	char	*line;
	char	*linebreak;
	char	*temp;

	linebreak = gnl_ft_strchr(*safe, '\n');
	*linebreak = '\0';
	line = gnl_ft_strjoin(*safe, "\n", 0);
	temp = *safe;
	*safe = gnl_ft_strjoin(NULL, linebreak + 1, 0);
	free(temp);
	return (line);
}

char	*end_of_file(char **safe)
{
	char	*line;

	if (**safe == '\0')
	{
		free(*safe);
		*safe = NULL;
		return (NULL);
	}
	line = *safe;
	*safe = NULL;
	return (line);
}
