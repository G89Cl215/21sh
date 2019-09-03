/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlistadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 14:07:46 by tgouedar          #+#    #+#             */
/*   Updated: 2019/08/08 14:41:34 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "d_list.h"

void		ft_dlistadd_start(t_dlist **alst, t_dlist *new_nod)
{
	t_dlist	*voyager;

	if (!(*alst))
		*alst = new_nod;
	else
	{
		voyager = *alst;
		while ((voyager->prev))
			voyager = voyager->prev;
		voyager->prev = new_nod;
		new_nod->next = voyager;
		*alst = new_nod;
	}
}

void		ft_dlistadd_back(t_dlist **alst, t_dlist *new_nod)
{
	t_dlist	*voyager;

	if (!(*alst))
		*alst = new_nod;
	else
	{
		voyager = *alst;
		while ((voyager->next))
			voyager = voyager->next;
		voyager->next = new_nod;
		new_nod->prev = voyager;
	}
}
