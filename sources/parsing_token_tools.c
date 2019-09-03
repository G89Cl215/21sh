/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_token_tools.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 18:25:10 by tgouedar          #+#    #+#             */
/*   Updated: 2019/07/04 23:40:58 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdlib.h>

t_arglist	*ft_next_plain_token(char *str, size_t *len, char *flag)
{
	size_t			i;
	t_arglist		*new_link;

	i = 0;
	*flag = NO_DELIM;
	while ((str[i]) && str[i] != ' ' && str[i] != '\t'
			&& str[i] != '\'' && str[i] != '\"')
		if (str[i++] == '\\' && !(str[i++]))
		{
			i--;
			*flag = NEWLINE;
			break ;
		}
	new_link = ft_listnewword(str, i, 0, NO_DELIM);
	if ((*flag))
		new_link->arg[i - 1] = '\0';
	new_link->to_link = (str[i] == ' ' || str[i] == '\t'
			|| (str[i] == '\0' && !(*flag)));
	*len += i;
	return (new_link);
}

t_arglist	*ft_next_quoted_token(char *str, size_t *len, char *flag)
{
	size_t			i;
	t_arglist		*new_link;

	i = 0;
	*flag = NO_DELIM;
	while ((str[i]) && str[i] != '\'')
		i++;
	if (!(str[i]))
	{
		*flag = QUOTES;
		i++;
	}
	new_link = ft_listnewword(str, i, 0, QUOTES);
	if (*flag == QUOTES)
	{
		new_link->arg[i--] = '\0';
		new_link->arg[i--] = '\n';
	}
	i++;
	new_link->to_link = (str[i] == ' ' || str[i] == '\t'
						|| (str[i] == '\0' && !(*flag)));
	*len += i;
	return (new_link);
}

t_arglist	*ft_next_dquoted_token(char *str, size_t *len, char *flag)
{
	size_t			i;
	t_arglist		*new_link;

	i = 0;
	*flag = NO_DELIM;
	while ((str[i]) && str[i] != '\"')
		if (str[i++] == '\\' && !(str[i++]))
		{
			i--;
			break ;
		}
	if (!(str[i]) && (++i))
		*flag = DQUOTES;
	new_link = ft_listnewword(str, i, 0, DQUOTES);
	if (*flag == DQUOTES)
	{
		new_link->arg[i--] = '\0';
		new_link->arg[i--] = '\n';
	}
	new_link->to_link = (str[++i] == ' ' || str[i] == '\t'
						|| (str[i] == '\0' && *flag == NO_DELIM));
	*len += i;
	return (new_link);
}
