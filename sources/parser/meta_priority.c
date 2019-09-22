/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_priority.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:14:32 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/22 13:08:50 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include "shell.h"
#include "list.h"

t_arglist			*ft_priority_meta(t_arglist *tokens)
{
	t_arglist	*res;

	res = NULL;
	while ((tokens))
	{
		ft_printf("\n on analyse la priorite de : {%s}, %i", tokens->arg, tokens->delim);
		if ((tokens->delim >= R_REDIR_APPEND && tokens->delim <= PIPE)
		&& (!(res) || ft_priority(tokens->delim) < ft_priority(res->delim)))
			res = tokens;
		tokens = tokens->next;
	}
	if ((res))
		ft_printf("\n la priorite max : {%s}\n", res->arg);
	else
		ft_putendl("\n NO METCHAR");
	return (res);
}
