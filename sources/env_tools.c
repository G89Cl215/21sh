/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 13:24:32 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/17 16:22:38 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell.h"
#include <stdlib.h>

char	*ft_get_env_var(t_env *env, char *var)
{
	size_t	i;
	size_t	len;
	char	*res;

	i = 0;
	len = ft_strlen(var);
	res = NULL;
	while ((env->value)[i])
	{
		if (!(ft_strncmp((env->value)[i], var, len))
		&& (env->value)[i][len] == '=')
		{
			if (!(res = ft_strdup((env->value)[i] + len + 1)))
				ft_crisis_exit(MALLOC_ERR);
			else
				break ;
		}
		i++;
	}
	return (res);
}

int		ft_env_index(t_env *env, char *var_name)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(var_name);
	while (((env->value)[i]) && (ft_strncmp((env->value)[i], var_name, len)
	|| (env->value)[i][len] != '='))
		i++;
	return ((env->value[i]) ? i : -1);
}

int		ft_set_env_var(t_env *env, char *var_name, char *var_value)
{
	int		i;
	char	*new_var;

	i = ft_env_index(env, var_name);
	if (!(new_var = ft_new_env(var_name, var_value)))
		ft_crisis_exit(MALLOC_ERR);
	if (i == -1)
	{
		i = 0;
		if (!(env->empty_lines) && ft_reallocate_env(env) == MALLOC_ERR)
			ft_crisis_exit(MALLOC_ERR);
		while ((env->value)[i])
			i++;
		env->empty_lines--;
	}
	else
		free((env->value)[i]);
	(env->value)[i] = new_var;
	return (1);
}

int		ft_unset_env_var(t_env *env, char *var_name)
{
	int		i;
	int		len;

	i = ft_env_index(env, var_name);
	if (i >= 0)
	{
		len = ft_tablen(env->value);
		ft_strdel(env->value + i);
		while (i < len)
		{
			env->value[i] = (env->value)[i + 1];
			i++;
		}
		env->empty_lines++;
	}
	return (i);
}
