/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_dlist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 14:18:29 by tgouedar          #+#    #+#             */
/*   Updated: 2019/08/08 16:41:08 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "d_list.h"
#include "libft.h"

int			ft_free_dlist(t_dlist **lst)
{
	t_dlist	*voyager;

	if (!(lst))
		return (0);
	voyager = ft_reset_dlist_head(*lst);
	*lst = voyager;
	while (voyager)
	{
		free(voyager->cmd_line);
		voyager = voyager->next;
		free(*lst);
		*lst = voyager;
	}
	return (1);
}
