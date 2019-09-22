/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_exec_fun.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 04:15:16 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/22 16:53:38 by tgouedar         ###   ########.fr       */
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
	int		pdes[2];
	int		*status;

	status = &(data->status);
	pipe(pdes);
	father = fork();
	if (father == 0)
	{
		ft_putendl("\n execution de gauche");
		dup2(pdes[WRITE], STDOUT_FILENO);
		close(pdes[READ]);
		ft_exec_struct(data, left_cmd);
		ft_putendl("\n execution de gauche finie");
		exit(0);
	}
	if (father > 0)
	{
		dup2(pdes[READ], STDIN_FILENO);
		close(pdes[WRITE]);
		waitpid(father, status, WUNTRACED);
		ft_putendl("\n attente de gauche finie");
		father = fork();
		if (father == 0)
		{
			ft_putendl("\n execution de droite");
			ft_exec_struct(data, right_cmd);
			close(pdes[READ]);
			exit(0);
		}
		else if (father > 0)
		{
			close(pdes[READ]);
			waitpid(father, status, WUNTRACED);
		}
		ft_putendl("que pasa ?");
//		exit(0);
//		open(0, O_RDONLY);
	}
	return (WIFEXITED(*status) || WIFSTOPPED(*status) ? EXEC_SUCCESS : EXEC_FAILURE);
}
