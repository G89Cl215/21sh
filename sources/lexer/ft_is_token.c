/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:58:42 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/17 19:00:59 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "libft.h"

int					ft_is_quoted_token(char *str, size_t *len, char flag)
{
	if (flag == QUOTES)
		return (1);
	if (flag != BQUOTES && flag != DQUOTES)
		if (str[*len] == '\'')
		{
			(*len)++;
			return (1);
		}
	return (0);
}

int					ft_is_dquoted_token(char *str, size_t *len, char flag)
{
	if (flag == DQUOTES)
		return (1);
	if (flag != QUOTES && flag != BQUOTES)
		if (str[*len] == '\"')
		{
			(*len)++;
			return (1);
		}
	return (0);
}

int					ft_is_bquoted_token(char *str, size_t *len, char flag)
{
	if (flag == BQUOTES)
		return (1);
	if (flag != QUOTES)
		if (str[*len] == '`')
		{
			(*len)++;
			return (1);
		}
	return (0);
}

int					ft_is_meta(char *str, size_t *len, char flag)
{
	if (flag == QUOTES || flag == BQUOTES || flag == DQUOTES)
		return (0);
	if (ft_is_in(str[*len], META_CHAR))
		return (1);
	return (0);
}
