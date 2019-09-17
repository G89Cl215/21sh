/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_tools2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 18:24:28 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/17 16:22:40 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell.h"
#include <stdlib.h>

char	*ft_new_env(char *var_name, char *var_value)
{
	size_t	i;
	size_t	len;
	char	*new_var;

	i = ft_strlen(var_name);
	len = i + 1 + ((var_value) ? ft_strlen(var_value) : 0);
	if (!(new_var = (char*)malloc(len + 1)))
		ft_crisis_exit(MALLOC_ERR);
	ft_memcpy(new_var, var_name, i);
	new_var[i] = '=';
	new_var[len] = '\0';
	if (var_value)
		ft_memcpy(new_var + i + 1, var_value, ft_strlen(var_value));
	return (new_var);
}

int		ft_reallocate_env(t_env *env)
{
	size_t	i;
	size_t	len;
	char	**new_tab;

	i = 0;
	len = ft_tablen(env->value);
	if (!(new_tab = (char**)malloc(sizeof(char*) * (2 * len + 1))))
		return (MALLOC_ERR);
	while (i < len)
	{
		if (!(new_tab[i] = ft_strdup(env->value[i])))
			return (MALLOC_ERR);
		i++;
	}
	while (i < 2 * len + 1)
		new_tab[i++] = NULL;
	env->empty_lines = len;
	ft_tabfree(env->value);
	env->value = new_tab;
	return (1);
}
