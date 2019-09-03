/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 01:47:34 by tgouedar          #+#    #+#             */
/*   Updated: 2019/08/29 11:36:08 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_listfree(t_arglist **alst)
{
	t_arglist	*next;

	while (alst && *alst)
	{
		next = (*alst)->next;
		ft_listfreeone(alst);
		(*alst) = next;
	}
}
