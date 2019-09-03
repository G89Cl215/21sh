/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_expanding_tilde.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 16:16:25 by tgouedar          #+#    #+#             */
/*   Updated: 2019/07/04 16:19:47 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "minishell.h"

static char	*ft_altilde_expand(t_env *env, t_arglist *arg, size_t i)
{
	size_t	len;
	char	*expansion;

	expansion = NULL;
	len = ft_strlen(arg->arg + i + 2) + 1;
	if (arg->arg[i + 1] == '-')
	{
		if ((expansion = ft_get_env_var(env, "OLDPWD")))
			expansion = ft_construct_expansion(arg->arg, expansion, i, 2);
		else
			ft_memmove(arg->arg + i, arg->arg + i + 2, len);
	}
	else if (arg->arg[i + 1] == '+')
	{
		if ((expansion = ft_get_env_var(env, "PWD")))
			expansion = ft_construct_expansion(arg->arg, expansion, i, 2);
		else
			ft_memmove(arg->arg + i, arg->arg + i + 2, len);
	}
	return (expansion);
}

void		ft_tilde_expand(t_env *env, t_arglist *arg)
{
	size_t	i;
	char	*expansion;

	i = 0;
	while ((arg->arg)[i])
	{
		expansion = NULL;
		if ((arg->arg)[i] == '~' && !(ft_is_escaped(arg->arg, i)))
		{
			if (!(expansion = ft_altilde_expand(env, arg, i))
					&& (expansion = ft_get_env_var(env, "HOME")))
				expansion = ft_construct_expansion(arg->arg, expansion, i, 1);
			else if (!(expansion))
				ft_memmove(arg->arg + i, arg->arg + i + 1,
						ft_strlen(arg->arg + i + 1) + 1);
		}
		if (expansion)
		{
			free(arg->arg);
			arg->arg = expansion;
		}
		i++;
	}
}
