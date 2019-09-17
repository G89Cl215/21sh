/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:30:33 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/17 20:15:21 by tgouedar         ###   ########.fr       */
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
# define TOKEN_DELIM		"\'\"\` \t"
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

int			ft_exec(t_env *env, t_env *env_exec, char **cmd_av, int *status);
int			ft_fork_and_exec(t_env *env, t_env *env_exec, char **av,
																int *status);
void		ft_display_err(t_env *env, char **av, int status, int w_index);
void		ft_mem_protect(void *to_allocate);
void		ft_crisis_exit(int status);
void		ft_free_data(t_data *data);
char		**ft_command_parsing(t_data *data, int *status);
void		ft_init_env(t_env *env);
char		*ft_find_exec_path(t_env *env, char *exec);
int			ft_built_in(t_env *env, char **av, int *status);
void		ft_built_in_usage(char *built_in);
char		*ft_find_exec(t_env *env, char *to_find);
char		*ft_build_path(char *path, char *exec);
char		*ft_get_env_var(t_env *env, char *var);
int			ft_set_env_var(t_env *env, char *var_name, char *var_value);
int			ft_unset_env_var(t_env *env, char *var_name);
int			ft_reallocate_env(t_env *env);
char		*ft_new_env(char *var_name, char *var_value);
t_arglist 	*ft_tokenizing(t_data *data);
void		ft_var_expanding(t_env *env, t_arglist *voyager, int *status);
void		ft_tilde_expand(t_env *env, t_arglist *arg);
void		ft_dollar_expand(t_env *env, t_arglist *arg, int status);
int			ft_star_match_expand(t_arglist *arg, int *status);
char		*ft_construct_expansion(char *arg, char *expansion, size_t var_pos,
																size_t var_len);
int			ft_is_escaped(char *str, int i);
void		ft_remove_slash(char *arg);

#endif
