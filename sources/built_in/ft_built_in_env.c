/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 17:31:48 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/22 11:12:35 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "def.h"
#include "libft.h"
#include "shell.h"
#include <stdlib.h>

static int		ft_set_tmp_env(t_env *tmp_env, char **av, size_t i)
{
	char	*eq;

	if (!(ft_strcmp(av[i], "-u")) && (av[i + 1]))
	{
		ft_unset_env_var(tmp_env, av[i + 1]);
		return (2);
	}
	if (!(ft_strcmp(av[i], "-P")) && (av[i + 1]))
	{
		ft_set_env_var(tmp_env, "PATH", av[i + 1]);
		return (2);
	}
	if ((eq = ft_strchr(av[i], '=')))
	{
		*(eq++) = '\0';
		ft_set_env_var(tmp_env, av[i], eq);
		*(--eq) = '=';
		return (1);
	}
	return (1);
}

static int		ft_construct_tmp_env(t_env *env, t_env *tmp_env, char **av,
																	size_t cmd)
{
	size_t	i;

	i = 1;
	if ((av[i]) && !(ft_strcmp(av[i], "-i")))
	{
		if (!(tmp_env->value = (char**)malloc(2 * sizeof(char*))))
			ft_crisis_exit(MALLOC_ERR);
		tmp_env->value[0] = NULL;
		tmp_env->value[1] = NULL;
		tmp_env->empty_lines = 1;
		i++;
	}
	else
	{
		tmp_env->value = ft_tabcpy(env->value);
		tmp_env->empty_lines = 0;
	}
	while (i < cmd)
		i += ft_set_tmp_env(tmp_env, av, i);
	return (0);
}

static size_t	ft_cmd_start(char **av)
{
	size_t		i;

	i = 1;
	if ((av[i]) && !(ft_strcmp(av[i], "-i")))
		i++;
	while (av[i])
	{
		if ((!(ft_strcmp(av[i], "-u")) && (av[i + 1]))
		|| (!(ft_strcmp(av[i], "-P")) && (av[i + 1])))
			i += 2;
		else if (ft_strchr(av[i], '='))
			i++;
		else
			break ;
	}
	return ((av[i]) ? i : 0);
}

int				ft_env(t_data *data, char **av)
{
	int		i;
	int		signal;
	t_env	*tmp_env;

	tmp_env = data->env_exec;
	i = ft_cmd_start(av);
	ft_construct_tmp_env(data->env, tmp_env, av, (i) ? i : ft_tablen(av));
	if (i == 0)
	{
		while (((tmp_env->value)[i]))
			ft_putendl((tmp_env->value)[i++]);
		ft_tabfree(tmp_env->value);
		return (data->status = EXEC_SUCCESS);
	}
	else
		signal = ft_exec(data, &(av[i]));
	if ((tmp_env->value))
		ft_tabfree(tmp_env->value);
	return (signal == EXEC_SUCCESS ? EXEC_SUCCESS : i);
}
