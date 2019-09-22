/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_parse_struc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 10:23:21 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/22 15:52:23 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "shell.h"


int			ft_exec_struct(t_data *data, t_meta_parse *to_exec)
{
	int		int_sig;
	char	**av;

	int_sig = 0;
	if ((to_exec->exec_func))
		int_sig = to_exec->exec_func(data, to_exec->left_cmd, to_exec->right_cmd);
	else if ((to_exec->tokens))
	{
		av = ft_make_args(to_exec->tokens);
/*
	int i = 0;
	while (av[i])
	{
		ft_putendl(av[i++]);
	}
*/
		int_sig = ft_exec(data, av);
		ft_tabfree(av);
//		exit(0);
	}
	return (int_sig);
}
