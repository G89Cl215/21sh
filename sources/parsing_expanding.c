/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_expanding.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 11:22:17 by tgouedar          #+#    #+#             */
/*   Updated: 2019/07/08 21:37:57 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "minishell.h"

static int		ft_to_star_expand(t_arglist *arg)
{
	size_t	i;

	i = 0;
	if (arg->delim == DQUOTES)
		return (0);
	while (arg->arg[i])
	{
		if ((arg->arg[i] == '\?' || arg->arg[i] == '*')
		&& !(ft_is_escaped(arg->arg, i)))
			return (1);
		i++;
	}
	return (0);
}

void			ft_var_expanding(t_env *env, t_arglist *voyager, int *status)
{
	int		i;

	while (voyager)
	{
		if (voyager->delim != QUOTES)
		{
			i = 0;
			if (voyager->delim != DQUOTES)
				ft_tilde_expand(env, voyager);
			ft_dollar_expand(env, voyager, *status);
			if (ft_to_star_expand(voyager)
			&& !(i = ft_star_match_expand(voyager, status)))
				return ;
			while (i-- > 0)
			{
				ft_remove_slash(voyager->arg);
				voyager = voyager->next;
			}
			ft_remove_slash(voyager->arg);
		}
		voyager = voyager->next;
	}
}
