/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_semi_col.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 13:07:25 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/25 13:17:40 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include "libft.h"
#include "shell.h"
#include "def.h"

int		ft_semi_col(t_data *data, void *left_cmd, void *right_cmd)
{
	int		int_signal;

	int_signal = ft_exec_struct(data, left_cmd, FORK);
	ft_putendl("\n execution de gauche finie");
	ft_putendl("\n execution de droite");
	ft_exec_struct(data, right_cmd, FORK);
	return (WIFEXITED(data->status) || WIFSTOPPED(data->status) ? EXEC_SUCCESS : EXEC_FAILURE);
}
