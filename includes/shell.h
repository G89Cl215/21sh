/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:30:33 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/23 21:00:53 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "list.h"
# include "def.h"

# define NAME "21sh"
# define PROMPT "21_tgoued"
# define NO_PROMPT ""
# define NL_PROMPT			"> "
# define QUOTES_PROMPT		"quotes> "
# define DQUOTES_PROMPT		"dquotes> "
# define BQUOTES_PROMPT		"bquotes> "
# define FORK				0
# define NO_FORK			1
# define EXEC_SUCCESS		0
# define EXEC_FAILURE		-1
# define EXIT_SIGNAL		-2
# define NOT_BI				-3
# define INVALID_OPTION		-4
# define MALLOC_ERR			-5
# define TARGET_NOT_FOUND	-6
# define NOT_A_CMD			-7
# define ARG_NBR_LOW		-8
# define ARG_NBR_HIGH		-9
# define ARG_NOT_NUM		-10
# define UNSET_VAR			-11
# define NO_MATCH			-12
# define ERR_NBR			6
# define IFS				" \t"
# define TOKEN_DELIM		"\'\"` \t"
# define META_CHAR			"><|;&"

# ifndef PATH_MAX
# define PATH_MAX			4096
#endif

# define NO_DELIM			0
# define NEWLINE			1
# define QUOTES				2
# define DQUOTES			3
# define BQUOTES			4
# define R_REDIR_APPEND		5
# define L_REDIR_APPEND		6
# define R_REDIR			7
# define L_REDIR			8
# define SEMI_COL			9
# define LOGIC_AND			10
# define AMPERSAND			11
# define LOGIC_OR			12
# define PIPE				13
# define DOLLAR_SPE			"?"

# define READ				0
# define WRITE				1

void		ft_display_err(t_env *env, char **av, int status, int w_index);
void		ft_mem_protect(void *to_allocate);
void		ft_crisis_exit(int status);
int			ft_free_data(t_data *data);

void		ft_init_env(t_env *env);
char		*ft_find_exec_path(t_env *env, char *exec);
int			ft_exec(t_data *data, char **cmd_av, char to_fork);
int			ft_exec_struct(t_data *data, t_meta_parse *to_exec, char to_fork);
int			ft_built_in(t_data *data, char **av);
void		ft_built_in_usage(char *built_in);
char		*ft_find_exec(t_env *env, char *to_find);
char		*ft_build_path(char *path, char *exec);

char		*ft_get_env_var(t_env *env, char *var);
int			ft_set_env_var(t_env *env, char *var_name, char *var_value);
int			ft_unset_env_var(t_env *env, char *var_name);
int			ft_reallocate_env(t_env *env);
char		*ft_new_env(char *var_name, char *var_value);

void		ft_var_expanding(t_env *env, t_arglist *voyager, int *status);
void		ft_tilde_expand(t_env *env, t_arglist *arg);
void		ft_dollar_expand(t_env *env, t_arglist *arg, int status);
int			ft_star_match_expand(t_arglist *arg, int *status);
char		*ft_construct_expansion(char *arg, char *expansion, size_t var_pos,
																size_t var_len);
int			ft_is_escaped(char *str, int i);
void		ft_remove_slash(char *arg);

void			ft_recognize_meta(const char *str, size_t *len,
															char *meta_flag);
t_arglist		*ft_tokenizing(t_data *data);
t_arglist		*ft_lexer(t_data *data);

int				ft_priority(char flag);
t_ft_meta		*ft_meta_function(char flag);
t_arglist		*ft_priority_meta(t_arglist *tokens, char *flag);
t_meta_parse	*ft_new_parse_struct(t_arglist *tokens);
void			ft_free_parse_struct(t_meta_parse *parse_struct);
char			**ft_make_args(t_arglist *arg_list);
int				ft_parser(t_data *data);


#endif
