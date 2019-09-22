/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_exec_fun.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 04:15:16 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/22 18:20:00 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include "libft.h"
#include "shell.h"
#include "def.h"

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
			ft_exec_struct(data, left_cmd);
			ft_putendl("\n execution de gauche finie");
			exit(0);
		}
		if (child > 0)
		{
			dup2(pdes[READ], STDIN_FILENO);
			close(pdes[WRITE]);
			waitpid(child, status, WUNTRACED);
			ft_putendl("\n attente de gauche finie");
			ft_putendl("\n execution de droite");
			ft_exec_struct(data, right_cmd);
			close(pdes[READ]);
			exit(0);
		}
		//		open(0, O_RDONLY);
	}
	else if (father > 0)
	{
		//			close(pdes[READ]);
		waitpid(father, status, WUNTRACED);
	}
	ft_putendl("que pasa ?");
	//		exit(0);
	return (WIFEXITED(*status) || WIFSTOPPED(*status) ? EXEC_SUCCESS : EXEC_FAILURE);
}
