/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 16:21:54 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/17 16:24:09 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <termios.h>
#include "cap_dispatcher.h"
#include "word_tools.h"
#include "line_edit.h"

int		ft_end_of_stream(t_data *data)
{
	char	*cmd_line;

	cmd_line = (data->cursor)->cmd_line;
	if (!(*cmd_line))
		return (EXIT_SIG);
	else
		return (ft_backspace(data));
}

int		ft_clear_screen_key(t_data *data)
{
	char		*tc;
	t_cursor	*cursor;

	cursor = data->cursor;
	tc = tgetstr("cl", NULL);
	tputs(tc, 1, &ft_pc);
	if ((cursor->line_form))
		ft_multiline_position(cursor, DOWN, ft_display_len(cursor->cmd_line));
	ft_update_line(cursor, NULL);
	return (1);
}
