/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 11:14:55 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/09 16:41:02 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <unistd.h>
#include <stdlib.h>

int		ft_exit(t_env *env, char **av, int *status)
{
	size_t	len;

	(void)env;
	len = ft_tablen(av);
	*status = EXEC_SUCCESS;
	if (len == 2)
	{
		if (ft_strisnum(av[1]))
			*status = ft_atoi(av[1]);
		else
		{
			*status = ARG_NOT_NUM;
			return (EXEC_FAILURE);
		}
	}
	else if (len > 2)
	{
		*status = ARG_NBR_HIGH;
		return (EXEC_FAILURE);
	}
	return (EXIT_SIGNAL);
}

int		ft_echo(t_env *env, char **av, int *status)
{
	size_t	i;

	i = 1;
	(void)env;
	while (av[i])
	{
		ft_putstr(av[i]);
		if (av[++i])
			ft_putchar(' ');
	}
	ft_putchar('\n');
	*status = EXEC_SUCCESS;
	return (EXEC_SUCCESS);
}
