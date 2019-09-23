/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 16:47:22 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/23 17:20:06 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_tabfree(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		ft_strdel(&(tab[i++]));
	free((void**)tab);
}
