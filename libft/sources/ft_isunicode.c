/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isunicode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 17:54:04 by tgouedar          #+#    #+#             */
/*   Updated: 2019/08/24 21:25:35 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_next_unicode(unsigned char *str)
{
	size_t	len;

	len = 1;
	while ((str[len]) && (str[len] >> 6) == 2)
		len++;
	return (len);
}

int				ft_isunicode(unsigned char *to_test)
{
	size_t			len;
	size_t			i;
	unsigned char	filter;

	if (!(to_test) || !(*to_test))
		return (0);
	while (*(to_test))
	{
		i = 0;
		filter = 128;
		len = ft_next_unicode(to_test);
		while ((*to_test & filter))
		{
			filter >>= 1;
			i++;
		}
		if ((len > 1 && len != i) || (len == 1 && !ft_isprint(*to_test)))
			return (0);
		to_test += len;
		ft_putstr((char *)to_test);
	}
	return (1);
}
