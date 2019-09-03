/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:06:55 by tgouedar          #+#    #+#             */
/*   Updated: 2019/08/29 15:59:29 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "def.h"
#include "libft.h"
#include "parsing.h"
#include "minishell.h"
#include <stdlib.h>

static size_t	ft_count_args(t_arglist *arg_list)
{
	size_t	ac;

	ac = 0;
	if (!(arg_list))
		return (0);
	while (arg_list->next)
	{
		ac += arg_list->to_link;
		arg_list = arg_list->next;
	}
	arg_list->to_link = 1;
	return (ac + 1);
}

static char		**ft_make_args(t_arglist *arg_list)
{
	size_t		i;
	size_t		ac;
	char		**av;
	t_arglist	*voyager;

	i = 0;
	ac = ft_count_args(arg_list);
	voyager = arg_list;
	if (!(av = (char**)malloc(sizeof(char*) * (ac + 1))))
		ft_crisis_exit(MALLOC_ERR);
	while (voyager && i < ac)
	{
		if (!(av[i] = ft_strdup(voyager->arg)))
			ft_crisis_exit(MALLOC_ERR);
		while (!(voyager->to_link) && (voyager->next))
		{
			voyager = voyager->next;
			if (!(ft_strappend(&(av[i]), &(voyager->arg))))
				ft_crisis_exit(MALLOC_ERR);
		}
		voyager = voyager->next;
		i++;
	}
	av[i] = NULL;
	return (av);
}

char			**ft_command_parsing(t_data *data, int *status)
{
	char			**av;
	t_arglist		*arg_list;

	arg_list = ft_tokenizing(data);
	ft_save_history(data, SAVE);
	ft_var_expanding(data->env, arg_list, status);
	av = ft_make_args(arg_list);
	ft_listfree(&arg_list);
	return (av);
}
