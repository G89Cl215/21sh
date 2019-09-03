/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tokenizing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 13:23:48 by tgouedar          #+#    #+#             */
/*   Updated: 2019/08/29 15:20:33 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include "parsing.h"
#include <stdlib.h>

static t_arglist	*ft_multiline_command(t_data *data)
{
	char			*line;
	t_arglist		*new_link;

	line = NULL;
	new_link = NULL;
//	ft_display_prompt();//flag);
	if ((ft_get_next_cmd_line(data)))
		new_link = ft_tokenizing(data);
	return (new_link);
}

static t_arglist	*ft_next_token(char *cmd, size_t *i, char *flag)
{
	t_arglist		*new_link;

	new_link = NULL;
	while ((ft_isin(cmd[*i], IFS)) && (*flag == NO_DELIM || *flag == NEWLINE))
		(*i)++;
	if (*flag == QUOTES || (*flag != DQUOTES && cmd[*i] == '\'' && ++(*i)))
		return (ft_next_quoted_token(cmd + *i, i, flag));
	if (*flag == DQUOTES || (*flag != QUOTES && cmd[*i] == '\"' && ++(*i)))
		return (ft_next_dquoted_token(cmd + *i, i, flag));
	if ((cmd[*i]))
		return (ft_next_plain_token(cmd + *i, i, flag));
	return (NULL);
}

t_arglist			*ft_tokenizing(t_data *data)
{
	size_t			i;
	t_arglist		*arg_list;
	char			flag;
	char			*cmd;

	i = 0;
	arg_list = NULL;
	cmd = (data->cursor)->cmd_line;
	flag = (data->cursor)->line_end;
	if (!(cmd[i]))
	{
		if (flag == QUOTES || flag == DQUOTES)
			ft_listadd_back(&arg_list, ft_listnewstr("\n", 0, flag));
		else if (flag == NEWLINE)
			flag = NO_DELIM;
	}
	while ((cmd[i]))
		ft_listadd_back(&arg_list, ft_next_token(cmd, &i, &flag));
	(data->cursor)->line_end = flag;
	if (flag != NO_DELIM)
		ft_listadd_back(&arg_list, ft_multiline_command(data));
	return (arg_list);
}
