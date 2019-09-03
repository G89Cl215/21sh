/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line_form.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 11:40:22 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/03 20:13:56 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "def.h"
#include "libft.h"
#include "minishell.h"

static size_t		ft_count_nl(const char *cmd_line)
{
	size_t		nl_nbr;
	size_t		i;

	nl_nbr = 0;
	i = 0;
	while (cmd_line[i])
	{
		if (cmd_line[i] == '\n')
			nl_nbr++;
		i++;
	}
	return (nl_nbr);
}

size_t				*ft_get_line_form(const char *cmd_line)
{
	size_t		*line_form;
	size_t		seg_nbr;
	size_t		i;
	size_t		j;

	j = 0;
	if ((seg_nbr = ft_count_nl(cmd_line) + 1) == 1)
		return (NULL);
	if (!(line_form = (size_t *)malloc(sizeof(size_t) * (seg_nbr + 1))))
		ft_crisis_exit(MALLOC_ERR);
	line_form[seg_nbr] = SIZE_MAX;
	while ((*cmd_line))
	{
		i = 0;
		while (*(cmd_line++) != '\n')
			i++;
		line_form[j] = i;
		j++;
	}
	return (line_form);
}

void				ft_update_line_form(t_cursor *cursor)
{
	if ((cursor->line_form))
		ft_memdel((void **)&(cursor->line_form));
	cursor->line_form = ft_get_line_form(cursor->cmd_line);
}
