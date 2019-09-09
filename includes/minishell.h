/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:17:05 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/09 16:42:19 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "list.h"
# include "def.h"

# define NAME "21sh"
# define PROMPT "21_tgoued"
# define NL_PROMPT			"> "
# define QUOTES_PROMPT		"quotes> "
# define DQUOTES_PROMPT		"dquotes> "
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

# ifndef PATH_MAX
# define PATH_MAX			4096
#endif

# define NO_DELIM			0
# define NEWLINE			1
# define QUOTES				2
# define DQUOTES			3
# define DOLLAR_SPE			"?"

int			ft_exec(t_env *env, t_env *env_exec, char **cmd_av, int *status);
int			ft_fork_and_exec(t_env *env, t_env *env_exec, char **av,
																int *status);
void		ft_display_err(t_env *env, char **av, int status, int w_index);
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
t_arglist	*ft_tokenizing(t_data *data);
t_arglist	*ft_next_plain_token(char *str, size_t *len, char *flag);
t_arglist	*ft_next_quoted_token(char *str, size_t *len, char *flag);
t_arglist	*ft_next_dquoted_token(char *str, size_t *len, char *flag);
void		ft_var_expanding(t_env *env, t_arglist *voyager, int *status);
void		ft_tilde_expand(t_env *env, t_arglist *arg);
void		ft_dollar_expand(t_env *env, t_arglist *arg, int status);
int			ft_star_match_expand(t_arglist *arg, int *status);
char		*ft_construct_expansion(char *arg, char *expansion, size_t var_pos,
																size_t var_len);
int			ft_is_escaped(char *str, int i);
void		ft_remove_slash(char *arg);

#endif
