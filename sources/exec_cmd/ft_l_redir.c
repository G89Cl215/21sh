/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_l_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 15:23:43 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/25 16:40:41 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"

static int	fork_in_redir(t_data *data, int fd, void *left_cmd)
{
	pid_t	father;
	int		*status;

	status = &(data->status);
	father = fork();
	if (father == 0)
	{
		dup2(fd, STDIN_FILENO);
		ft_exec_struct(data, left_cmd, NO_FORK);
	}
	else if (father > 0)
		waitpid(father, status, WUNTRACED);
	return (WIFEXITED(*status) || WIFSTOPPED(*status) ? EXEC_SUCCESS : EXEC_FAILURE);
}

int		ft_l_redir(t_data *data, void *left_cmd, void *right_cmd)
{
	char	*file_name;
	int		int_signal;
	int		fd;

	int_signal = EXEC_FAILURE;
	file_name = ((t_meta_parse*)right_cmd)->tokens->arg;
	if ((fd = open(file_name, O_RDONLY)) != -1)
		int_signal = fork_in_redir(data, fd, left_cmd);
	close(fd);
	return (int_signal);
}
/*
int		ft_l_redir_heredoc(t_data *data, void *left_cmd, void *right_cmd)
{
	char	*file_name;
	int		int_signal;
	int		fd;

	int_signal = EXEC_FAILURE;
	file_name = ((t_meta_parse*)right_cmd)->tokens->arg;
	if ((fd = open(file_name, O_RDONLY)) != -1)
		int_signal = fork_in_redir(data, fd, left_cmd);
	close(fd);
	return (int_signal);
}*/
