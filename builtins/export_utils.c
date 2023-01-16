/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 06:18:43 by tayeo             #+#    #+#             */
/*   Updated: 2023/01/16 06:54:25 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		printf("declare -x %s\n", envp[i]);
		i++;
	}
}

/*
** if flag is set to 1 -> returned string must be freed
** else -> do not free
*/
char *get_name(char *str, int *flag)
{
	char	*var_name;
	char	*delimiter;

	delimiter = ft_strchr(str, '=');
	if (delimiter != NULL)
	{
		*delimiter = 0;
		var_name = ft_strdup(str);
		*delimiter = '=';
		*flag = 1;
		return (var_name);
	}
	return (str);
}

int	check_name(char *str)
{
	int	i;

	i = 0;
	if (ft_isdigit(str[0]))
		return (0);
	while (str[i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

char	**add_env(char **envp, char *str)
{
	char	**dupe;
	int		i;

	i = 0;
	while (envp[i])
		i++;
	dupe = (char **)malloc(sizeof(char *) * (i + 2));
	if (!dupe)
		return (NULL);
	dupe[i + 1] = 0;
	dupe[i] = ft_strdup(str);
	while (i > 0)
	{
		i--;
		dupe[i] = ft_strdup(envp[i]);
	}
	free_double_ptr(envp);
	return (dupe);
}
