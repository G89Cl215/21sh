/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 12:06:54 by tgouedar          #+#    #+#             */
/*   Updated: 2019/08/26 19:38:23 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "parsing.h"
#include "dispatcher.h"
#include "libft.h"
#include "d_list.h"
#include "word_tools.h"

void	ft_load_history(t_data *data)
{
	size_t		len;
	t_cursor	*cursor;

	cursor = data->cursor;
	ft_bzero(cursor->cmd_line, MAX_LINE);
	len = ft_strlen((data->history)->cmd_line);
	ft_memcpy(cursor->cmd_line, (data->history)->cmd_line, len);
	cursor->char_cursor = len;
	cursor->line_len = len;
	cursor->display_cursor = ft_display_len(cursor->cmd_line);
}

void	ft_clean_history(t_dlist **history)
{
	t_dlist		*voyager;

	if ((*history))
	{
		voyager = *history;
		while ((voyager->prev))
			voyager = voyager->prev;
		*history = voyager;
		while ((voyager))
		{
			if (voyager->status == CUR_CMD)
				voyager = ft_del_dnod(voyager);
			else
				voyager = voyager->next;
		}
	}
}

int		ft_up_cursor(t_data *data)
{
	t_cursor	*cursor;

	cursor = data->cursor;
	if (!(cursor->in_history))
	{
		cursor->in_history = 1;
		ft_dlistadd_start(&(data->history),
				ft_new_dnod(cursor->cmd_line, CUR_CMD));
	}
	if ((data->history) && ((data->history)->next))
	{
		data->history = (data->history)->next;
		ft_load_history(data);
		ft_update_line(cursor, NULL);
	}
	return (1);
}

int		ft_down_cursor(t_data *data)
{
	t_cursor	*cursor;

	cursor = data->cursor;
	if (!(cursor->in_history))
	{
		cursor->in_history = 1;
		ft_dlistadd_start(&(data->history),
				ft_new_dnod(cursor->cmd_line, CUR_CMD));
	}
	if ((data->history) && (data->history)->prev)
	{
		data->history = (data->history)->prev;
		ft_load_history(data);
		ft_update_line(cursor, NULL);
	}
	return (1);
}
