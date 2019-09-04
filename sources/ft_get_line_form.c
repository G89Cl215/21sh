/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line_form.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 11:40:22 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/04 16:00:37 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "def.h"
#include "libft.h"
#include "minishell.h"
#include "word_tools.h"

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
		while ((*cmd_line) && *(cmd_line++) != '\n')
		{
			while (((*cmd_line & bit_8) && !(*cmd_line & bit_7)))
				cmd_line++;
			i++;
		}
		line_form[j] = i;
		j++;
	}
	return (line_form);
}

int					ft_get_multiline_hight(size_t *line_form, int ref)
{
	int		hight;
	int		char_nbr;

	hight = 0;
	if ((line_form))
	{
		char_nbr = line_form[hight];
		while (line_form[hight] != SIZE_MAX && (ref < 0 || char_nbr < ref))
		{
			hight++;
			char_nbr += line_form[hight];
		}
		if (line_form[hight] == SIZE_MAX)
			hight--;
	}
	return (hight);
}

void				ft_update_line_form(t_cursor *cursor)
{
	if ((cursor->line_form))
		ft_memdel((void **)(&(cursor->line_form)));
	cursor->line_form = ft_get_line_form(cursor->cmd_line);
}
