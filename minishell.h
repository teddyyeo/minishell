/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijeong <jijeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:27:44 by jijeong           #+#    #+#             */
/*   Updated: 2023/01/02 10:42:21 by jijeong          ###   ########.fr       */
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

#endif
