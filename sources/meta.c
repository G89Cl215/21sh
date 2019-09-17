/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:47:19 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/17 20:15:21 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "meta_dispatcher.h"

t_meta	g_meta_dispatcher[] =
{
	{"|\0", PIPE, PIPE_PRIO},
	{NULL, 0, 0/*, NULL*/}
};

void		ft_recognize_meta(const char *str, size_t *len, char *meta_flag)
{
	size_t		i;

	i = 0;
	while (g_meta_dispatcher[i].meta)
	{
		if (!ft_strncmp(g_meta_dispatcher[i].meta, str, 1)
		|| !ft_strncmp(g_meta_dispatcher[i].meta, str, 2))
		{
			*len = ft_strlen(g_meta_dispatcher[i].meta);
			*meta_flag = g_meta_dispatcher[i]
			return ;
		}
		i++;
	}
}

