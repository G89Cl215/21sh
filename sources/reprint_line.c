/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reprint_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 16:11:47 by tgouedar          #+#    #+#             */
/*   Updated: 2019/08/29 15:26:39 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <termios.h>
#include <term.h>
#include "libft.h"
#include "def.h"
#include "parsing.h"
#include "word_tools.h"

void	ft_insert_buff_in_line(t_cursor *cursor, char *buff)
{
	char	tmp[MAX_LINE];
	size_t	len;

	if (!(buff))
		return ;
	len = ft_strlen(buff);
	if (cursor->char_cursor + len < MAX_LINE)
	{
		ft_memcpy(tmp, cursor->cmd_line + cursor->char_cursor,
				ft_strlen(cursor->cmd_line + cursor->char_cursor) + 1);
		ft_memcpy(cursor->cmd_line + cursor->char_cursor, buff, len);
		cursor->char_cursor += len;
		cursor->display_cursor += ft_display_len(buff);
		ft_memcpy(cursor->cmd_line + cursor->char_cursor, tmp, ft_strlen(tmp));
		cursor->line_len += len;
	}
}

void	ft_update_line(t_cursor *cursor, char *buff)
{
	char		*tc;
	size_t		i;

	ft_clear_line(cursor);
	ft_display_prompt();
	ft_insert_buff_in_line(cursor, buff);
	write(0, cursor->cmd_line, cursor->line_len);
	i = ft_display_len(cursor->cmd_line);
	if (!((i + ft_display_len(PROMPT)) % ft_get_term_length()))
	{
		tc = tgetstr("do", NULL);
		tputs(tc, 1, &ft_pc);
	}
	ft_cursor_reset(i);
	ft_position_cursor(cursor);
}
