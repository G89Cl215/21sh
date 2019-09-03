/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ascii_cmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 14:06:38 by tgouedar          #+#    #+#             */
/*   Updated: 2019/08/07 14:22:16 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "d_list.h"
#include "libft.h"

int		ft_dlist_ascii_cmp(t_dlist *lst1, t_dlist *lst2)
{
	return (ft_strcmp(lst2->cmd_line, lst1->cmd_line));
}
