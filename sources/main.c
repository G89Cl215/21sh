/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 14:46:24 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/18 03:07:15 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "signal_manager.h"
#include "shell.h"
#include "line_edit.h"
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
			waitpid(0, status, WUNTRACED);
		ft_set_env_var(env, "_", execpath);
		free(execpath);
		return (WIFEXITED(*status) || WIFSTOPPED(*status) ? EXEC_SUCCESS : EXEC_FAILURE);
	}
	else
		*status = NOT_A_CMD;
	return (EXEC_FAILURE);
}

int		ft_exec(t_env *env, t_env *env_exec, char **cmd_av, int *status)
{
	int		signal;

	signal = ft_built_in(env_exec, cmd_av, status);
	if (signal == NOT_BI)
	{
		toggle_sig_mode();
		signal = ft_fork_and_exec(env, env_exec, cmd_av, status);
		if (signal == EXEC_FAILURE && *status != NOT_A_CMD)
			*status = WEXITSTATUS(*status);
		toggle_sig_mode();
	}
	return (signal);
}

int		main(void)
{
	char		*line;
	t_data		data;

	ft_init_data(&data);
	ft_sig_setup();
	raw_term_mode();
	line = NULL;
	while (1)
	{
		if ((ft_get_next_cmd_line(&data)))
			ft_parser(&data);
		else if (!(data.status = 0))
		{
			ft_putstr("\n");
			ft_putendl("exit");
			break ;
		}
	}
	restore_term_mode(&data);
	return (ft_free_data(&data));
}
