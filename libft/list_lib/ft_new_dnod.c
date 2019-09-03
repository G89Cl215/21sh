/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_dnod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:42:30 by tgouedar          #+#    #+#             */
/*   Updated: 2019/08/08 14:41:37 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "d_list.h"
#include "libft.h"

t_dlist		*ft_new_dnod(char *cmd_line, int status)
{
	t_dlist	*new_nod;

	if (!(new_nod = (t_dlist*)malloc(sizeof(t_dlist))))
		return (NULL);
	if (!(new_nod->cmd_line = ft_strdup(cmd_line)))
		return (NULL);
	new_nod->status = status;
	new_nod->prev = NULL;
	new_nod->next = NULL;
	return (new_nod);
}
