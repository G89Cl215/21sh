/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 12:06:54 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/17 16:26:18 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <termios.h>
#include <term.h>
#include "line_edit.h"
#include "bi_dispatcher.h"
#include "libft.h"
#include "d_list.h"
#include "word_tools.h"

static void		ft_multiline_scrolling(int to_scroll)
{
	char	*tc;

	if (!(to_scroll))
		return ;
	tc = (to_scroll > 0) ? tgetstr("do", NULL) : tgetstr("up", NULL);
	if (to_scroll < 0)
		to_scroll = -1 * to_scroll;
	while ((to_scroll))
	{
		tputs(tc, 1, &ft_pc);
		to_scroll--;
	}
}

void			ft_load_history(t_data *data)
{
	int			to_scroll;
	size_t		len;
	t_cursor	*cursor;

	to_scroll = 0;
	cursor = data->cursor;
	if ((cursor->line_form))
		to_scroll -= ft_get_multiline_hight(cursor->line_form,
													cursor->display_cursor);
	cursor = data->cursor;
	ft_bzero(cursor->cmd_line, MAX_LINE);
	len = ft_strlen((data->history)->cmd_line);
	ft_memcpy(cursor->cmd_line, (data->history)->cmd_line, len);
	cursor->char_cursor = len;
	cursor->line_len = len;
	cursor->display_cursor = ft_display_len(cursor->cmd_line);
	ft_update_line_form(cursor);
	if ((cursor->line_form))
		to_scroll += ft_get_multiline_hight(cursor->line_form, -1);
	ft_multiline_scrolling(to_scroll);
}

void			ft_clean_history(t_dlist **history)
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

int				ft_up_cursor(t_data *data)
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

int				ft_down_cursor(t_data *data)
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
