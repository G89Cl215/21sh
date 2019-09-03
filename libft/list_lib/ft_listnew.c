/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:33:48 by baavril           #+#    #+#             */
/*   Updated: 2019/08/29 11:36:45 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "libft.h"
#include <stdlib.h>

t_arglist		*ft_listnewstr(char const *arg, int to_link, char delim)
{
	t_arglist *new;

	if (!(new = (t_arglist*)malloc(sizeof(*new))))
		return (NULL);
	if (arg == NULL)
		new->arg = NULL;
	else if (!(new->arg = ft_strdup(arg)))
		return (NULL);
	new->next = NULL;
	new->to_link = to_link;
	new->delim = delim;
	return (new);
}

t_arglist		*ft_listnewword(char const *arg, size_t n, int to_link,
																	char delim)
{
	t_arglist *new;

	if (!(new = (t_arglist*)malloc(sizeof(*new))))
		return (NULL);
	if (arg == NULL)
		new->arg = NULL;
	else if (!(new->arg = ft_strnew(n)))
		return (NULL);
	ft_memccpy(new->arg, arg, '\0', n);
	new->next = NULL;
	new->to_link = to_link;
	new->delim = delim;
	return (new);
}
