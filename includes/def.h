/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 18:57:08 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/08 13:14:42 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_H
# define DEF_H

# include <stddef.h>
# include "d_list.h"

# define MAX_KEY_SIZE		8
# define MAX_LINE			4096
# define DOWN				0
# define UP					1
# define NEW_CMD			1
# define SAVE				1

typedef struct		s_env
{
	char			**value;
	int				empty_lines;
}					t_env;

typedef struct		s_cursor
{
	char			cmd_line[MAX_LINE];
	size_t			line_len;
	size_t			display_cursor;
	size_t			char_cursor;
	size_t			*line_form;
	char			line_end;
	char			in_history;
}					t_cursor;

typedef struct		s_data
{
	t_env			*env;
	t_dlist			*history;
	t_cursor		*cursor;
	char			clipboard[MAX_LINE];
}					t_data;

#endif
