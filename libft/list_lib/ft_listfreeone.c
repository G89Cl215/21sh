/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listfreeone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 01:47:36 by tgouedar          #+#    #+#             */
/*   Updated: 2019/08/29 11:42:53 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "libft.h"
#include <stdlib.h>

void	ft_listfreeone(t_arglist **alst)
{
	if (alst && *alst)
	{
		free((*alst)->arg);
		ft_memdel((void**)alst);
	}
}
