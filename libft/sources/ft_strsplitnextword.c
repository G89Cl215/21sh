/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitnextword.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:26:03 by tgouedar          #+#    #+#             */
/*   Updated: 2019/04/15 17:30:28 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

static size_t	ft_word_len(char const *str, char c)
{
	size_t	k;

	k = 0;
	while (*str && *str - c)
	{
		str++;
		k++;
	}
	return (k);
}

char			*ft_strsplitnextword(char const *str, char c)
{
	if (!str || !c)
		return (NULL);
	return (ft_strndup(str, ft_word_len(str, c)));
}
