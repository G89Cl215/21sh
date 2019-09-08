/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 16:26:15 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/08 11:40:44 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <term.h>
#include "libft.h"
#include "parsing.h"
#include "word_tools.h"

static void		ft_multiline_cursor_goto(t_cursor *cursor, size_t *vert, size_t *hor, size_t ref)
{
	size_t		len;
	size_t		co;
	size_t		i;

	i = 0;
	len = ft_prompt_len(cursor->line_end);
	*vert = 0;
	*hor = len;
	len += (cursor->line_form)[0];
	co = ft_get_term_length();
	while (ref > 0)
	{
		if (*hor < co && *hor < len)
			(*hor)++;
		else
		{
			if (*hor == len)
				len = (cursor->line_form)[++i];
			else
				len -= co;
			*hor = 0;
			(*vert)++;
		}
		ref--;
	}
}

void			ft_multiline_wrap(t_cursor *cursor, int flag)
{
	char		*tc;
	size_t		vert;
	size_t		hor;
	size_t		nl;

	ft_multiline_cursor_goto(cursor, &vert, &hor, cursor->display_cursor);
	if (flag == UP && !(hor % ft_get_term_length()))
	{
		tc = tgetstr("up", NULL);
		tputs(tc, 1, &ft_pc);
	}
	else
	{
		nl = (cursor->line_form)[vert] + !(vert) * ft_prompt_len(cursor->line_end);
		if (flag == DOWN && (!((hor + 1) % ft_get_term_length()) || (hor == nl)))
		{
			tc = tgetstr("do", NULL);
			tputs(tc, 1, &ft_pc);
		}
	}
}

void			ft_reajust_cursor_wrap(t_cursor *cursor, int flag)
{
	char		*tc;
	size_t		i;

	if ((cursor->line_form))
	{
		ft_multiline_wrap(cursor, flag);
		return ;
	}
	i = ft_prompt_len(cursor->line_end) + cursor->display_cursor;
	if (flag == UP && !(i % ft_get_term_length()))
	{
		tc = tgetstr("up", NULL);
		tputs(tc, 1, &ft_pc);
	}
	else if (flag == DOWN && !((i + 1) % ft_get_term_length()))
	{
		tc = tgetstr("do", NULL);
		tputs(tc, 1, &ft_pc);
	}
}


void			ft_multiline_position(t_cursor *cursor, char flag, size_t ref)
{
	char		*buff;
	size_t		vert;
	size_t		hor;

	ft_multiline_cursor_goto(cursor, &vert, &hor, ref);
	buff = (flag == DOWN) ? tgetstr("do", NULL) : tgetstr("up", NULL);
	while ((vert))
	{
		tputs(buff, 1, &ft_pc);
		vert--;
	}
	buff = tgetstr("ch", NULL);
	buff = tgoto(buff, 0, hor);
	tputs(buff, 1, &ft_pc);
}

void	ft_cursor_reset(t_cursor *cursor, size_t ref)
{
	char	*buff;
	size_t	pos;
	size_t	co;

	if (!(cursor->line_form))
	{
		pos = ft_prompt_len(cursor->line_end) + ref;
		co = ft_get_term_length();
		if ((co))
			pos /= co;
		buff = tgetstr("up", NULL);
		while (pos)
		{
			tputs(buff, 1, &ft_pc);
			pos--;
		}
	}
	else
		ft_multiline_position(cursor, UP, ref);
	buff = tgetstr("ch", NULL);
	buff = tgoto(buff, 1, 0);
	tputs(buff, 1, &ft_pc);
}

void			ft_position_cursor(t_cursor *cursor)
{
	char		*buff;
	size_t		pos;
	size_t		co;

	if (!(cursor->line_form))
	{
		pos = ft_prompt_len(cursor->line_end) + cursor->display_cursor;
		co = ft_get_term_length();
		buff = tgetstr("do", NULL);
		while (pos >= co)
		{
			tputs(buff, 1, &ft_pc);
			pos -= co;
		}
		buff = tgetstr("ch", NULL);
		buff = tgoto(buff, 0, pos);
		tputs(buff, 1, &ft_pc);
	}
	else
		ft_multiline_position(cursor, DOWN, cursor->display_cursor);
}
