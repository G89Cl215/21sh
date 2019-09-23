/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:32:31 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/23 21:33:43 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "line_edit.h"
#include "libft.h"
#include "shell.h"
#include "def.h"

int				ft_parse_into_struct(t_meta_parse *to_parse, char flag)
{
	t_arglist		*voyager;
	t_arglist		*end_of_cmd;

	if (!(end_of_cmd = to_parse->tokens)
	&& flag != NO_DELIM && flag != SEMI_COL)
		return (1); // erreur de parsing -> une des section de la commande en bout de ligne est vide
	if (!(voyager = ft_priority_meta(to_parse->tokens, &flag)))
		return (0);
	ft_putendl("\n ON DETECTE LES METACHARS");
	to_parse->exec_func = ft_meta_function(voyager->delim);
	to_parse->right_cmd = ft_new_parse_struct(voyager->next);
	if (voyager == end_of_cmd)
		return (1); //erreur de parsing -> on commence par un metachar / deux meta d'affilee
	else
	{
		while (end_of_cmd->next != voyager)
			end_of_cmd = end_of_cmd->next;
		end_of_cmd->next = NULL;
	}
	ft_listfreeone(&voyager);
	to_parse->left_cmd = ft_new_parse_struct(to_parse->tokens);
	to_parse->tokens = NULL;
	return (ft_parse_into_struct(to_parse->left_cmd, flag) || ft_parse_into_struct(to_parse->right_cmd, flag));
}

int					ft_parser(t_data *data)
{
	int				res;
	t_arglist		*tokens;
	t_meta_parse	*parse_struct;

	res = 0;
	tokens = ft_lexer(data); //protection contre le token == NULL -> return plus rapide ?
	parse_struct = ft_new_parse_struct(tokens);
	ft_putendl("\n strcut start");
	if (ft_parse_into_struct(parse_struct, NO_DELIM))
	{
		res = EXEC_FAILURE;
		ft_printf("%s: parse error: check your metacharacters.\n", NAME);
	}
	else
	{
		ft_putendl("\n strcut exec");
		toggle_sig_mode();
		res = ft_exec_struct(data, parse_struct, FORK);
		toggle_sig_mode();
		ft_putendl("\n strcut exec end");
		ft_free_parse_struct(parse_struct);
	}
	return (res);
}
