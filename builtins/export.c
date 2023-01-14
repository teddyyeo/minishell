/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:56:34 by tayeo             #+#    #+#             */
/*   Updated: 2023/01/14 14:49:17 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	**dupe_env(char **envp)
{
	char	**dupe;
	int	i;

	while (envp[i])
		i++;
	dupe = (char **)malloc(sizeof(char *) * (i + 1));
	if (!dupe)
		return (NULL);
	dupe[i] = 0;
	while (i > 0)
	{
		i--;
		dupe[i] = ft_strdup(envp[i]);
	}
	return (dupe);
}

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

void	sort_print_env(char **envp)
{
	char	**dup;
	char	*tmp;
	size_t	i;
	size_t	j;

	dup = dupe_env(envp);
	i = 0;
	while (dup[i])
	{
		j = i + 1;
		while (dup[j])
		{
			if (ft_strcmp(dup[i], dup[j]) > 0)
			{
				tmp = dup[i];
				dup[i] = dup[j];
				dup[j] = tmp;
			}
			j++;
		}
		i++;
	}
	print_env(dup);
	free_double_ptr(dup);
}

void export(char **argv, char **envp)
{
	int	i;

	i = 0;
	if (argv == NULL)
		sort_print_env(envp);


}

/*
** 1. if there are no arguments, print sorted env with "declare -x"
** 2. if there are arguments, check if they are valid variable names
** 3. if valid -> check if the variable name exists already -> if it does replace definiton, else add to the env list
** 4. if not valid -> say so
*/
char *seperate_var_name(char *str)
{

}
int	check_var_name(char *str)
{
	int	i;

	i = 0;
	if (ft_isdigit(str[0]))
		return (0);
	while (str[i] != 0)
	{
		if (!ft_isalnum(str[i]) || str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

int main(int argc, char **argv, char **envp)
{
	export(NULL, envp);
}
