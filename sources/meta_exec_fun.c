/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_exec_fun.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 04:15:16 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/18 06:24:50 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "def.h"

int		ft_pipe(void *left_cmd, void *right_cmd)
{
	pid_t	
	int		pdes[2];

	pipe(pdes);
	father = fork();
	if (father == 0)
	{
		dup2(pdes[0], STDIN_FILENO);
		clode(pdes[1]);
		ft_exec_struct(left_cmd);
	}
	if (father > 0)
	{
		waitpid(0, status, WUNTRACED);
		father = fork();
		if (father == 0)
		{
			dup2(pdes[1], STDOUT_FILENO);
			clode(pdes[0]);
			ft_exec_struct(right_cmd);
		}
		if (father > 0)
			waitpid(0, status, WUNTRACED);
		return (WIFEXITED(*status) || WIFSTOPPED(*status) ? EXEC_SUCCESS : EXEC_FAILURE);
	}
	
}
