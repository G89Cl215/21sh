/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 16:17:38 by tgouedar          #+#    #+#             */
/*   Updated: 2019/05/20 16:41:32 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**ft_tabcpy(char **tab)
{
	char	**cpy;
	size_t	len;

	len = ft_tablen(tab) + 1;
	if (!(cpy = (char**)malloc(sizeof(char*) * len)))
		return (NULL);
	len = 0;
	while (tab[len])
	{
		if (!(cpy[len] = ft_strdup(tab[len])))
			return (NULL);
		len++;
	}
	cpy[len] = NULL;
	return (cpy);
}
