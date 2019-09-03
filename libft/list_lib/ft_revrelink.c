/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revrelink.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 15:21:13 by tgouedar          #+#    #+#             */
/*   Updated: 2019/08/07 14:19:35 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "d_list.h"

void		ft_revrelink(t_dlist *voyager, t_dlist *new_nod)
{
	new_nod->prev = voyager->prev;
	new_nod->next = voyager;
	if (voyager->prev)
		(voyager->prev)->next = new_nod;
	voyager->prev = new_nod;
}
