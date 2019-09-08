/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 14:46:24 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/08 16:27:33 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "minishell.h"
#include "parsing.h"
#include "signal.h"
#include "libft.h"

int		ft_fork_and_exec(t_env *env, t_env *env_exec, char **av, int *status)
{
	pid_t		father;
	char		*execpath;

	if ((execpath = ft_find_exec(env, av[0])))
	{
		father = fork();
		if (father == 0)
				execve(execpath, av, env_exec->value);	//return status si non-executable/faillure to execute
		if (father > 0)
			wait(status);
		ft_set_env_var(env, "_", execpath);
		free(execpath);
		return (WIFEXITED(*status) ? EXEC_SUCCESS : EXEC_FAILURE);
	}
	else
		*status = NOT_A_CMD;
	return (EXEC_FAILURE);
}

int		ft_exec(t_env *env, t_env *env_exec, char **cmd_av, int *status)
{
	int		sig;

	sig = ft_built_in(env_exec, cmd_av, status);
	if (sig == NOT_BI)
	{
		toggle_sig_mode();
		sig = ft_fork_and_exec(env, env_exec, cmd_av, status);
		if (sig == EXEC_FAILURE && *status != NOT_A_CMD)
			*status = WEXITSTATUS(*status);
		toggle_sig_mode();
	}
	return (sig);
}

int		ft_treat_line(t_data *data, int *status)
{
	int			signal;
	char		**cmd_av;

	signal = 0;
	if (!(cmd_av = ft_command_parsing(data, status)))
		ft_crisis_exit(MALLOC_ERR);
	if (*status != NO_MATCH && cmd_av[0])
	{
		signal = ft_exec(data->env, data->env, cmd_av, status);
		if (signal != EXEC_SUCCESS)
			ft_display_err(data->env, cmd_av, *status, signal);
	}
	else if (*status == NO_MATCH)
		*status = EXEC_FAILURE;
	ft_tabfree(cmd_av);
	return (signal);
}

int		main(void)
{
	char		*line;
	t_data		data;
	int			status;

	ft_sig_setup();
	ft_init_data(&data);
	raw_term_mode();
	line = NULL;
	status = 0;
	while (1)
	{
		if ((ft_get_next_cmd_line(&data)))
		{
			if (ft_treat_line(&data, &status) == EXIT_SIGNAL)
				break ;
		}
		else if (!(status = 0))
		{
			ft_putstr("\n");
			ft_putendl("exit");
			break ;
		}
	}
	def_term_mode();
	ft_free_data(&data);
	return (status);
}
