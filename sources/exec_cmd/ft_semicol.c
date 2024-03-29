/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_semi_col.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 13:07:25 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/25 13:39:09 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include "shell.h"

int		ft_semi_col(t_data *data, void *left_cmd, void *right_cmd)
{

	ft_exec_struct(data, left_cmd, FORK);
	ft_exec_struct(data, right_cmd, FORK);
	return (WIFEXITED(data->status) || WIFSTOPPED(data->status) ? EXEC_SUCCESS : EXEC_FAILURE);
}
