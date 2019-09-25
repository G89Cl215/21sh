/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 04:15:16 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/25 15:31:20 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "libft.h"
#include "shell.h"

int		ft_pipe(t_data *data, void *left_cmd, void *right_cmd)
{
	pid_t	father;
	pid_t	child;
	int		pdes[2];
	int		*status;

	status = &(data->status);
	father = fork();
	if (father == 0)
	{
		pipe(pdes);
		child = fork();
		if (child == 0)
		{
			ft_putendl("\n execution de gauche");
			dup2(pdes[WRITE], STDOUT_FILENO);
			close(pdes[READ]);
			ft_exec_struct(data, left_cmd, NO_FORK);
			ft_putendl("\n execution de gauche finie");
		}
		if (child > 0)
		{
			dup2(pdes[READ], STDIN_FILENO);
			close(pdes[WRITE]);
			waitpid(child, status, WUNTRACED);
			ft_putendl("\n attente de gauche finie");
			ft_putendl("\n execution de droite");
			ft_exec_struct(data, right_cmd, NO_FORK);
		}
		close(pdes[READ]);
	}
	else if (father > 0)
		waitpid(father, status, WUNTRACED);
	ft_putendl("que pasa ?");
	return (WIFEXITED(*status) || WIFSTOPPED(*status) ? EXEC_SUCCESS : EXEC_FAILURE);
}
