/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_dnod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 14:44:48 by tgouedar          #+#    #+#             */
/*   Updated: 2019/08/24 21:50:35 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "d_list.h"
#include <stdlib.h>

t_dlist		*ft_del_dnod(t_dlist *nod_to_del)
{
	t_dlist		*tmp;

	tmp = NULL;
	if ((nod_to_del))
	{
		if ((nod_to_del->prev))
			(nod_to_del->prev)->next = nod_to_del->next;
		if ((nod_to_del->next))
			(nod_to_del->next)->prev = nod_to_del->prev;
		tmp = nod_to_del->next;
		free(nod_to_del->cmd_line);
		free(nod_to_del);
	}
	return (tmp);
}
