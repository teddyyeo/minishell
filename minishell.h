/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:27:44 by jijeong           #+#    #+#             */
/*   Updated: 2023/01/17 00:14:47 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_token
{
	char			*token;
	int				code;
	struct s_token	*next;
}					t_token;

typedef struct s_redi
{
	char				*filename;
	char				*eof;
	int					redi_code;
	struct s_redirect	*next;
}						t_redi;

typedef struct s_cmds_set
{
	pid_t	pid;
	t_redi	*redirection;
	char	**cmds;
	int		id;
}			t_cmds_set;

typedef struct s_cmds_sets
{
	int			pipenum;
	t_cmds_set	*cmds_set;
}			t_cmds_sets;

typedef struct s_env
{
	char	**envp;
}			t_env;

typedef struct s_mslist
{
	int			status;
	t_token		*token;
	int			token_len;
	t_cmds_sets	*cmds_sets;
	int			multicmd;
	t_env		env;
}				t_mslist;

// ms_parse.c
int		ms_parse(t_mslist *l, char *cmd);
// ms_tokenize.c
int		ms_tokenize(t_mslist *l, char *cmd);
int		ms_ismeta(char c);
int		ms_get_meta_token(t_mslist *l, size_t *i, size_t *j, char *cmd);
int		ms_get_word_token(t_mslist *l, size_t *i, size_t *j, char *cmd);
int		ms_pass_quote(size_t *i, char *cmd, char c);
int		ms_add_token(t_mslist *l, char *token);
int		ms_set_token_code(t_token *token);
int		ms_set_meta_token_code(t_token *token);
int		ms_token_interpreter(t_token *token);
int		ms_check_ambiguous_redirect(char *str);
int		ms_isverable(char c);
char	*ms_get_key(char *str);
// ms_parameter_expansion.c
// ms_word_splitting.c
// ms_globbing.c
// ms_token to cmd.c
// ms_excute.c
// ms_free.c
int		ms_free_token(t_mslist *l);
// ms_error.c
int		ms_error_msg(char *s, int exit_code);

/*
** builtins/export.c
*/
int	export(t_mslist *list, char **args);
void	sort_print_env(char **envp);
void	check_exist_add(t_mslist *list, char *str);
void	update(t_mslist *list, char *str, int i);

/*
** builtins/export_utils.c
*/
void	print_env(char **envp);
char	**add_env(char **envp, char *str);
char *get_name(char *str, int *flag);
int	check_name(char *str);


/*
** builtins/env.c
*/
void	env(char **envp);

/*
** builtin/pwd.c
*/
void	pwd(void);

/*
** builtins/utils.c
*/
char	**dupe_env(char **envp);
int		get_env_num(char **envp);
void	free_double_ptr(char **arr);
int		ft_strcmp(const char *s1, const char *s2);
void	free_ptr(char *ptr, int *flag);

/*
** builtins/unset.c
*/
int		unset(t_mslist *list, char **args);
int		check_match(char **envp, char *str);
char	**remove_env(t_mslist *list, char *var_name);
#endif
