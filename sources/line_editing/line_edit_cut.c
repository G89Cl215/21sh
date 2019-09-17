/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_edit_cut.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 14:43:53 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/17 16:26:39 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "def.h"
#include "line_edit.h"
#include "word_tools.h"

int		ft_cut_from_cursor(t_data *data)
{
	t_cursor	*cursor;

	cursor = data->cursor;
	ft_save_in_clipboard(data, cursor->cmd_line + cursor->char_cursor,
									cursor->line_len - cursor->char_cursor);
	ft_bzero(cursor->cmd_line + cursor->char_cursor,
									cursor->line_len - cursor->char_cursor);
	cursor->line_len = ft_strlen(cursor->cmd_line);
	ft_update_line(cursor, NULL);
	return (1);
}

int		ft_cut_cmd(t_data *data)
{
	t_cursor	*cursor;

	cursor = data->cursor;
	ft_save_in_clipboard(data, cursor->cmd_line, ft_strlen(cursor->cmd_line));
	ft_init_cursor(cursor, NEW_CMD);
	ft_update_line(cursor, NULL);
	return (1);
}

int		ft_cut_prev_word(t_data *data)
{
	size_t		word_start;
	size_t		word_len;
	t_cursor	*cursor;

	cursor = data->cursor;
	word_start = cursor->char_cursor;
	word_len = ft_prev_word_start(cursor->cmd_line, word_start);
	word_start -= word_len;
	ft_save_in_clipboard(data, cursor->cmd_line + word_start, word_len);
	ft_memmove(cursor->cmd_line + word_start,
			cursor->cmd_line + cursor->char_cursor,
			ft_strlen(cursor->cmd_line + word_start) + 1);
	cursor->char_cursor -= word_len;
	ft_bzero(cursor->cmd_line + ft_strlen(cursor->cmd_line), word_len);
	cursor->display_cursor = ft_cursor_conv_char_to_display(cursor->cmd_line,
														cursor->char_cursor);
	cursor->line_len = ft_strlen(cursor->cmd_line);
	ft_update_line(cursor, NULL);
	return (1);
}

int		ft_paste_clipboard(t_data *data)
{
	size_t	len;
	t_cursor	*cursor;

	cursor = data->cursor;
	len = ft_strlen(data->clipboard);
	if ((len) && len + cursor->line_len < MAX_LINE)
		ft_update_line(cursor, data->clipboard);
	return (1);
}
