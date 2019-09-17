/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:32:31 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/17 18:50:57 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "line_edit.h"
#include "libft.h"
#include "shell.h"
#include "def.h"


t_meta_parse		*ft_new_parse_struct(t_arglist *tokens)
{
	t_meta_parse	*parse_struct;

	ft_mem_protect(parse_struct = (t_meta_parse*)malloc(sizeof(*parse_struct)));
	parse_struct->tokens = tokens;
	parse_struct->left_cmd = NULL;
	parse_struct->right_cmd = NULL;
}

void				ft_parse_into_struct(t_meta_parse *to_parse)
{
	t_arglist		*voyager;

	if (!(voyager = ft_priority_meta(to_parse->tokens)))
		return ;
	to_parse->ft_meta = ft_meta_fct(voyager->delim);
	to_parse->right_cmd = ft_new_parse_struct(voyager->next);
	ft_listfreeone(&voyager);
	to_parse->left_cmd = ft_new_parse_struct(to_parse->tokens);
	ft_parse_into_struct(to_parse->left_cmd);
	ft_parse_into_struct(to_parse->right_cmd);
	to_parse->tokens = NULL;
}

int					ft_parser(t_data *data)
{
	int				res;
	t_arglist		*tokens;
	t_meta_parse	*parse_struct;

	tokens = ft_lexer(data); //protection contre le token == NULL -> return plus rapide ?
	parse_struct = ft_new_parse_struct(tokens);
	ft_parse_into_struct(parse_struct);
	res = ft_exec_struct(parse_struct);
	ft_free_struct(parse_struct);
	return (res);
}
