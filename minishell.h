/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:27:44 by jijeong           #+#    #+#             */
/*   Updated: 2023/01/17 23:17:18 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_token
{
	char			*token;
	int				code;
	struct s_token	*next;
}					t_token;

typedef struct s_cmd
{
	char			*cmd;
	struct s_cmd	*next;
}					t_cmd;

typedef struct s_redi
{
	char			*filename;
	int				redi_code;
	struct s_redi	*next;
}					t_redi;

typedef struct s_cmds_set
{
	t_redi			*redi;
	t_cmd			*command;
	int				id;
}					t_cmds_set;

typedef struct s_cmds_list
{
	int				*pipe;
	int				pipenum;
	pid_t			*pid;
	t_cmds_set		*cmds_set;
}					t_cmds_list;

typedef struct s_env
{
	char			**envp;
}					t_env;

typedef struct s_mslist
{
	int				status;
	t_token			*token;
	int				token_len;
	t_cmds_list		*cmds_list;
	int				multicmd;
	t_env			env;
}					t_mslist;

// ms_parse.c
int					ms_parse(t_mslist *l, char *cmd);
// ms_tokenize.c
int					ms_tokenize(t_mslist *l, char *cmd);
int					ms_ismeta(char c);
int					ms_get_meta_token(t_mslist *l, size_t *i, size_t *j,
						char *cmd);
int					ms_get_word_token(t_mslist *l, size_t *i, size_t *j,
						char *cmd);
int					ms_pass_quote(size_t *i, char *cmd, char c);
int					ms_add_token(t_mslist *l, char *token);
int					ms_set_token_code(t_token *token);
int					ms_check_redi_token_code(t_token *token, int pre_code);
int					ms_check_token_code(t_token *token);
int					ms_set_meta_token_code(t_token *token);
// ms_here_doc.c
int					ms_make_here_doc(t_mslist *l);
// ms_token_to_cmd.c
int					ms_set_command_struct(t_mslist *l);
int					ms_set_command_list_struct(t_mslist *l);
int					ms_set_command_list(t_mslist *l, int i, int j);
int					ms_set_command_set_struct(t_mslist *l);
int					ms_set_redi_cmd_sets(t_mslist *l, int i, int j);
int					ms_add_cmd_list(t_cmds_set *cmds, t_token *token);
int					ms_add_redi_list(t_cmds_set *cmds, t_token *token);
// ms_parse_line.c
int					ms_parse_str(t_mslist *l, char *str, int split);
// ms_parameter_expansion.c
// ms_word_splitting.c
// ms_globbing.c
// ms_excute.c
int					ms_execute(t_mslist *l, int cnt_list, int cnt_cmd);
int					ms_set_redirection(t_mslist *l, int cnt_list, int cnt_cmd);
int					ms_set_pipe_fd(t_mslist *l, int cnt_list, int cnt_cmd);
int					waiting_child(t_mslist *l, int cnt_list);
// ms_set_data.c
int					ms_set_data(t_mslist *l, char **argv, char **envp);
// ms_free.c
int					ms_free_data(t_mslist *l);
// ms_error.c
int					ms_error_msg(char *s, int exit_code);

/*
** builtins!
*/

/*
** builtins/export.c
*/
void				export(t_mslist *list, char **args);
void				sort_print_env(char **envp);
void				check_exist_add(t_mslist *list, char *str);
void				update(t_mslist *list, char *str, int i);
int					export_error(char *str, char *name, t_mslist *list);

/*
** builtins/export_utils.c
*/
void				print_env(char **envp);
char				**add_env(char **envp, char *str);
char				*get_name(char *str, int *flag);
int					check_name(char *str);
char				*get_defi(char *str);

/*
** builtins/env.c
*/
void				env(t_mslist *list, char **args);

/*
** builtin/pwd.c
*/
void				pwd(t_mslist *list);

/*
** builtins/utils.c
*/
char				**dupe_env(char **envp);
int					get_env_num(char **envp);
void				free_double_ptr(char **arr);
int					ft_strcmp(const char *s1, const char *s2);
void				free_ptr(char *ptr, int *flag);

/*
** builtins/unset.c
*/
int					unset(t_mslist *list, char **args);
int					check_match(char **envp, char *str);
char				**remove_env(t_mslist *list, char *var_name);

/*
** builtin/utils2.c
*/
char				*get_env_var(char **envp, char *str);
void				malloc_error_handler(void *ptr);

/*
** builtin/cd.c
*/
void				cd(t_mslist *list, char *path);

/*
** builtin/echo.c
*/
void				echo(t_mslist *list, char **argv);

/*
** builtin/exit.c
*/
void				exit_builtin(t_mslist *list, char **argv);

void				signaling(void);
#endif
