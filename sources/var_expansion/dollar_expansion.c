/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_expanding_dollar.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 18:29:04 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/17 16:27:48 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "shell.h"

static char		*ft_get_dolspeexpansion(char spe, int status)
{
	if (spe == '\?')
		return (ft_itoa(status));
	return (NULL);
}

static size_t	ft_dolspecialexpand(t_arglist *arg, size_t i, int status)
{
	char	*expansion;
	size_t	len;

	expansion = ft_get_dolspeexpansion(arg->arg[i + 1], status);
	len = ft_strlen(expansion);
	expansion = ft_construct_expansion(arg->arg, expansion, i, 2);
	free(arg->arg);
	arg->arg = expansion;
	return (len);
}

static char		*ft_next_dolword(char *src)
{
	size_t	len;

	len = 0;
	while ((src[len]) && src[len] != '$')
		len++;
	return (ft_strndup(src, len));
}

static char		*ft_construct_dollar_expansion(t_env *env, t_arglist *arg,
														size_t *i, int status)
{
	size_t	len;
	char	*to_expand;
	char	*expansion;

	expansion = NULL;
	if (ft_isin(arg->arg[*i + 1], DOLLAR_SPE))
		*i += ft_dolspecialexpand(arg, *i, status);
	else
	{
		to_expand = ft_next_dolword(arg->arg + *i + 1);
		len = ft_strlen(to_expand) + 1;
		if ((expansion = ft_get_env_var(env, to_expand)))
		{
			expansion = ft_construct_expansion(arg->arg, expansion, *i, len);
			*i += len;
		}
		else
			ft_memmove(arg->arg + *i, arg->arg + *i + len,
					ft_strlen(arg->arg + *i + len) + 1);
		free(to_expand);
	}
	return (expansion);
}

void			ft_dollar_expand(t_env *env, t_arglist *arg, int status)
{
	size_t	i;
	char	*expansion;

	i = 0;
	while ((arg->arg)[i])
	{
		expansion = NULL;
		if ((arg->arg)[i] == '$' && !(ft_is_escaped(arg->arg, i)))
			expansion = ft_construct_dollar_expansion(env, arg, &i, status);
		if (expansion)
		{
			free(arg->arg);
			arg->arg = expansion;
		}
		i++;
	}
}
