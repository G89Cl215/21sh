/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 13:06:53 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/09 16:16:55 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include "minishell.h"
#include "ft_printf.h"
#include "parsing.h"
#include "signal.h"

void	ft_plop(int nbr)
{
	ft_printf("\nSIG_NB : %d.\n", nbr);
}

void	ft_signal_manager(int sig_nbr)
{
//	t_data		*data;
//	pid_t		pid;

	ft_plop(sig_nbr);
	if (sig_nbr == 18)
	{
//		pid = getpid();
//		f_term_mode();
//		kill(pid, sig_nbr);
	}
	if (sig_nbr == 19)
	{
		raw_term_mode();
/*		data = get_data();
		ft_update_line(data->cursor, NULL);*/
	}
	if (sig_nbr == 2)
		ft_printf("%s: program interrupted by peer.", NAME);
//	if (sig == 1)
}

void	ft_sig_setup(void)
{
	size_t		i;

	i = 0;
	while (i++ < 31)
		signal(i, ft_signal_manager);
}
