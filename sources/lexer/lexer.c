/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:58:14 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/17 20:15:21 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "token_dispatcher.h"
#include "shell.h"
#include "line_edit.h"
#include "libft.h"

t_token				g_token_dispatcher[] =
{
	{ft_is_quoted_token, ft_next_quoted_token},
	{ft_is_dquoted_token, ft_next_dquoted_token},
	{ft_is_bquoted_token, ft_next_bquoted_token},
	{ft_is_meta, ft_next_meta_token},
	{NULL, NULL}
};

static t_arglist	*ft_multiline_command(t_data *data)
{
	t_arglist		*new_link;

	new_link = NULL;
	if ((ft_get_next_cmd_line(data)))
		new_link = ft_tokenizing(data);
	return (new_link);
}

static t_arglist	*ft_next_token(char *cmd, size_t *i, char *flag)
{
	size_t		j;

	while ((ft_isin(cmd[*i], IFS)) && (*flag == NO_DELIM || *flag == NEWLINE))
		(*i)++;
	if (!(cmd[*i]))
		return(NULL);
	j = 0;
	while (!(g_token_dispatcher[j].ft_is_token(cmd, i, *flag)))
	{
		j++;
		if (!(g_token_dispatcher[j].ft_is_token))
			return (ft_next_plain_token(cmd + *i, i, flag));
	}
	return (g_token_dispatcher[j].ft_next_token(cmd + *i, i, flag));
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

t_arglist			*ft_relink_tokens(t_arglist *arg_list)
{
	t_arglist	*voyager;
	t_arglist	*new_list;
	char		*token;

	new_list = NULL;
	voyager = arg_list;
	while ((voyager))
	{
		ft_mem_protect(token = ft_strdup(voyager->arg));
		while (!(voyager->to_link) && (voyager->next))
		{
			voyager = voyager->next;
			if (!(ft_strappend(&token, &(voyager->arg))))
				ft_crisis_exit(MALLOC_ERR);
		}
		ft_listadd_back(&new_list, ft_listnewstr(token, 1, voyager->delim));
		voyager = voyager->next;
		free(token);
	}
	ft_listfree(&arg_list);
	return (new_list);
}

t_arglist	*ft_lexer(t_data *data)
{
	t_arglist		*arg_list;

	arg_list = ft_tokenizing(data);
	ft_save_history(data, SAVE);
	ft_var_expanding(data->env, arg_list, &(data->status));
//	ft_interpret_bquotes();
	arg_list = ft_relink_tokens(arg_list);
/*	av = ft_make_args(arg_list);
	ft_listfree(&arg_list);*/
	return (arg_list);
}
