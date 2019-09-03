/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_cmd_line.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 07:52:01 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/03 17:52:26 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <termios.h>
#include <term.h>
#include "libft.h"
#include "d_list.h"
#include "def.h"
#include "dispatcher.h"
#include "parsing.h"
/*
#include <stdio.h>

void	print_bytes(void *ptr, int size)
{
	int				i;
	unsigned char	*p;

	p = ptr;
	i = 0;
	while (i < size)
	{
		i++;
		printf("%02hhX ", p[i]);
	}
	printf("\n\r");
}
*/
int		ft_pc(int c)
{
	return (write(0, &c, 1));
}

void	ft_clear_line(t_cursor *cursor)
{
	char	*buff;

	ft_cursor_reset(cursor, cursor->display_cursor);
	buff = tgetstr("cd", NULL);
	tputs(buff, 1, &ft_pc);
}

int		ft_get_next_cmd_line(t_data *data)
{
	int			i;
	char		buff[MAX_KEY_SIZE];
	t_cursor	*cursor;

	cursor = data->cursor;
	ft_init_cursor(cursor, 0);
	ft_display_prompt(cursor->line_end);
	ft_memset(buff, '\0', MAX_KEY_SIZE);
	while (read(0, buff, MAX_KEY_SIZE) > 0)
	{
		if (!(i = ft_termcap(buff, data)))
			ft_update_line(cursor, buff);
		else if (i == ENTER_SIG)
			break ;
		else if (i == EXIT_SIG)
			return (0);
		ft_memset(buff, '\0', MAX_KEY_SIZE);
	}
	return (1);
}
