/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_dlist_head.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 16:35:10 by tgouedar          #+#    #+#             */
/*   Updated: 2019/08/08 16:41:09 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "d_list.h"

t_dlist		*ft_reset_dlist_head(t_dlist *voyager)
{
	if (voyager)
		while ((voyager->prev))
			voyager = voyager->prev;
	return (voyager);
}
