/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_priority.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:14:32 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/18 03:49:19 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "list.h"

t_arglist			*ft_priority_meta(t_arglist *tokens)
{
	t_arglist	*res;

	res = NULL;
	while ((tokens))
	{
		if ((tokens->delim >= R_REDIR_APPEND && tokens->delim <= PIPE)
		&& (!(res) || ft_priority(tokens->delim) < ft_priority(res->delim)))
			res = tokens;
		tokens = tokens->next;
	}
	return (res);
}
