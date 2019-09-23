/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 14:46:24 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/23 20:58:04 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "signal_manager.h"
#include "line_edit.h"
#include "shell.h"
#include "libft.h"

int		main(void)
{
	char		*line;
	t_data		data;

	ft_init_data(&data);
	ft_sig_setup();
	raw_term_mode();
	line = NULL;
	while (1)
	{
		if ((ft_get_next_cmd_line(&data)))
		{
			if (ft_parser(&data) == EXIT_SIGNAL)
				break ;
		}
		else if (!(data.status = 0))
		{
			ft_putstr("\n");
			ft_putendl("exit");
			break ;
		}
	}
	restore_term_mode(&data);
	return (ft_free_data(&data));
}
