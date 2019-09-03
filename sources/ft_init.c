/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 18:16:49 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/03 14:14:37 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/param.h>
#include "def.h"
#include "libft.h"
#include "minishell.h"

static int		ft_def_env_gen(t_env *env)
{
	char	pwd[PATH_MAX];

	if (!(env->value = (char**)malloc(2 * sizeof(char*))))
		ft_crisis_exit(MALLOC_ERR);
	env->value[0] = NULL;
	env->value[1] = NULL;
	env->empty_lines = 1;
	getcwd(pwd, PATH_MAX);
	ft_set_env_var(env, "PWD", pwd);
	ft_set_env_var(env, "SHLVL", "1");
	ft_set_env_var(env, "TERM", "xterm-256color");
	return (0);
}

void			ft_init_env(t_env *env)
{
	extern char		**environ;
	char			*shlvl;
	int				lvl;

	env->empty_lines = 0;
	if (!(environ[0]))
		ft_def_env_gen(env);
	else
	{
		if (!(env->value = ft_tabcpy(environ)))
			ft_crisis_exit(MALLOC_ERR);
		if ((shlvl = ft_get_env_var(env, "SHLVL")))
		{
			lvl = ft_atoi(shlvl) + 1;
			free(shlvl);
			shlvl = ft_itoa(lvl);
			ft_set_env_var(env, "SHLVL", shlvl);
			free(shlvl);
		}
		else
			ft_set_env_var(env, "SHLVL", "1");
	}
}

void	ft_init_cursor(t_cursor *cursor, char flag)
{
	ft_memset(cursor->cmd_line, '\0', MAX_LINE);
	cursor->line_len = 0;
	if (flag == NEW_CMD)
		cursor->line_end = NO_DELIM;
	cursor->display_cursor = 0;
	cursor->char_cursor = 0;
	cursor->in_history = 0;
	cursor->line_form = NULL;
}

void	ft_init_data(t_data *data)
{
	if (!(data->cursor = (t_cursor*)malloc(sizeof(t_cursor))))
		ft_crisis_exit(MALLOC_ERR);
	ft_init_cursor(data->cursor, NEW_CMD);
	if (!(data->env = (t_env*)malloc(sizeof(t_env))))
		ft_crisis_exit(MALLOC_ERR);
	ft_init_env(data->env);
	ft_bzero(data->clipboard, MAX_LINE);
	data->history = NULL;
}
