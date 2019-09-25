/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic_or.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 13:31:51 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/25 13:47:46 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include "shell.h"

int		ft_logic_or(t_data *data, void *left_cmd, void *right_cmd)
{
	if (ft_exec_struct(data, left_cmd, FORK) == EXEC_FAILURE)
		ft_exec_struct(data, right_cmd, FORK);
	return (WIFEXITED(data->status) || WIFSTOPPED(data->status) ? EXEC_SUCCESS : EXEC_FAILURE);
}
