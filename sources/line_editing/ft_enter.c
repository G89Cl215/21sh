/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 14:48:35 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/17 16:25:00 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "line_edit.h"
#include "libft.h"
#include "shell.h"

static void		ft_concat_lines(char **line, char *to_add)
{
	size_t		line_len;
	size_t		add_len;
	char		*new;

	if (!(line) || !(to_add))
		return ;
	if (!(*line))
	{
		if (!(*line = ft_strdup(to_add)))
			ft_crisis_exit(MALLOC_ERR);
	}
	else
	{
		line_len = ft_strlen(*line);
		add_len = ft_strlen(to_add);
		if (!(new = ft_strnew(line_len + add_len + 1)))
			ft_crisis_exit(MALLOC_ERR);
		ft_memcpy(new, *line, line_len);
		new[line_len] = '\n';
		ft_memcpy(new + line_len + 1, to_add, add_len + 1);
		free(*line);
		*line = new;
	}
}

void			ft_save_history(t_data *data, char flag)
{
	static char		*history_entry = NULL;

	if ((history_entry) && flag == SAVE)
	{
		ft_dlistadd_start(&(data->history),
				ft_new_dnod(history_entry, PAST_CMD));
		ft_strdel(&history_entry);
		ft_clean_history(&(data->history));
	}
	else
		ft_concat_lines(&history_entry, (data->cursor)->cmd_line);
}

int				ft_enter(t_data *data)
{
	t_cursor		*cursor;

	cursor = data->cursor;
	ft_save_history(data, 0);
	ft_update_line(cursor, NULL);
	ft_putchar('\n');
	return (ENTER_SIG);
}
