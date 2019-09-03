/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_relink.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 15:22:06 by tgouedar          #+#    #+#             */
/*   Updated: 2019/08/07 14:43:01 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "d_list.h"

void		ft_relink(t_dlist *voyager, t_dlist *new_nod)
{
	new_nod->prev = voyager;
	new_nod->next = voyager->next;
	if (voyager->next)
		(voyager->next)->prev = new_nod;
	voyager->next = new_nod;
}
