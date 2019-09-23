/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 11:14:55 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/23 17:30:33 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell.h"
#include <unistd.h>
#include <stdlib.h>

int		ft_exit(t_data *data, char **av)
{
	size_t	len;

	len = ft_tablen(av);
	data->status = EXEC_SUCCESS;
	if (len == 2)
	{
		if (ft_strisnum(av[1]))
			data->status = ft_atoi(av[1]);
		else
		{
			data->status = ARG_NOT_NUM;
			return (EXEC_FAILURE);
		}
	}
	else if (len > 2)
	{
		data->status = ARG_NBR_HIGH;
		return (EXEC_FAILURE);
	}
	return (EXIT_SIGNAL);
}

int		ft_echo(t_data *data, char **av)
{
	size_t	i;

	i = 1;
	while (av[i])
	{
		ft_putstr(av[i]);
		if (av[++i])
			ft_putchar(' ');
	}
	ft_putchar('\n');
	data->status = EXEC_SUCCESS;
	return (EXEC_SUCCESS);
}
