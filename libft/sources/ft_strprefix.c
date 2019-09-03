/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strprefix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 18:02:44 by tgouedar          #+#    #+#             */
/*   Updated: 2019/05/06 18:02:47 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		ft_strprefix(char **src, char **dest)
{
	char	*tmp;
	size_t	i;

	i = ft_strlen(*dest) + ft_strlen(*src) + 1;
	if (!(tmp = (char*)malloc(i)))
		return (0);
	ft_memcpy(tmp, *src, ft_strlen(*src) + 1);
	tmp = ft_strcat(tmp, *dest);
	ft_memdel((void**)dest);
	ft_memdel((void**)src);
	*dest = tmp;
	return (1);
}
