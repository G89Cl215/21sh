/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_struct_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 02:02:28 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/23 17:35:00 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shell.h"
#include "list.h"

t_meta_parse		*ft_new_parse_struct(t_arglist *tokens)
{
	t_meta_parse	*parse_struct;

	ft_mem_protect(parse_struct = (t_meta_parse*)malloc(sizeof(*parse_struct)));
	parse_struct->tokens = tokens;
	parse_struct->exec_func = NULL;
	parse_struct->left_cmd = NULL;
	parse_struct->right_cmd = NULL;
	return (parse_struct);
}

void				ft_free_parse_struct(t_meta_parse *parse_struct)
{
	if (parse_struct->left_cmd)
		ft_free_parse_struct(parse_struct->left_cmd);
	if (parse_struct->right_cmd)
		ft_free_parse_struct(parse_struct->right_cmd);
	if (parse_struct->tokens)
		ft_listfree(&(parse_struct->tokens));
	free(parse_struct);
}
