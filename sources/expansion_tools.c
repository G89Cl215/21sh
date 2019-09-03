/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:59:47 by tgouedar          #+#    #+#             */
/*   Updated: 2019/07/08 21:58:17 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "minishell.h"

int		ft_is_escaped(char *str, int i)
{
	int		cnt;

	cnt = 1;
	while (cnt <= i && str[i - cnt] == '\\')
		cnt++;
	return ((cnt - 1) % 2);
}

char	*ft_construct_expansion(char *arg, char *expansion, size_t var_pos,
																size_t var_len)
{
	size_t		len;
	char		*res;

	len = ft_strlen(expansion);
	if (!(res = ft_strnew(len + ft_strlen(arg) - var_len)))
		ft_crisis_exit(MALLOC_ERR);
	ft_memcpy(res, arg, var_pos);
	ft_memcpy(res + var_pos, expansion, len);
	ft_memcpy(res + len + var_pos, arg + var_len + var_pos,
						ft_strlen(arg + var_pos + var_len));
	free(expansion);
	return (res);
}

void	ft_remove_slash(char *arg)
{
	size_t		i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '\\')
		{
			ft_memmove(arg + i, arg + i + 1, ft_strlen(arg + i));
			if (!(arg[i]))
				break ;
		}
		i++;
	}
}
