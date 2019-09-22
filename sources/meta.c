/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:47:19 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/22 12:13:35 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "meta_dispatcher.h"
#include "shell.h"
#include "libft.h"

t_meta	g_meta_dispatcher[] =
{
/*	{">>", R_REDIR_APPEND, R_REDIR_APPEND_PRIO, ft_r_redir_append},
	{"<<", L_REDIR_APPEND, L_REDIR_APPEND_PRIO, ft_l_redir_append},
	{">", R_REDIR, R_REDIR_PRIO, ft_r_redir},
	{"<", L_REDIR, L_REDIR_PRIO, ft_l_redir},
	{";", SEMI_COL, SEMI_COL_PRIO, ft_semi_col},
	{"&&", LOGIC_AND, LOGIC_AND_PRIO, ft_logic_and},
	{"&", AMPERSAND, AMPERSAND_PRIO, ft_ampersand},
	{"||", LOGIC_OR, LOGIC_OR_PRIO, ft_logic_or},*/
	{"|\0", PIPE, PIPE_PRIO, ft_pipe},
	{NULL, 0, INT_MAX, NULL}
};

int			ft_priority(char flag)
{
	size_t		i;

	i = 0;
	while ((g_meta_dispatcher[i].meta) && g_meta_dispatcher[i].flag != flag)
		i++;
	return (g_meta_dispatcher[i].priority);
}

t_ft_meta	*ft_meta_function(char flag)
{
	size_t		i;

	i = 0;
	while ((g_meta_dispatcher[i].meta) && g_meta_dispatcher[i].flag != flag)
		i++;
	return (g_meta_dispatcher[i].exec_func);
}

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
			*meta_flag = g_meta_dispatcher[i].flag;
			return ;
		}
		i++;
	}
}
