/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 13:06:53 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/09 20:10:32 by tgouedar         ###   ########.fr       */
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
	pid_t		pid;

	ft_plop(sig_nbr);
	pid = getpid();
	if (sig_nbr == SIGTSTP || sig_nbr == SIGSTOP)
		ft_printf("%s: program stopped by peer.\n", NAME);
	if (sig_nbr == SIGCONT)
	{}
	if (sig_nbr == SIGCHLD)
		ft_printf("The child has been touched...\n");
	if (sig_nbr == 2)
		ft_printf("%s: program interrupted by peer.\n", NAME);
//	if (sig == 1)
}

void	ft_sig_setup(void)
{
	size_t		i;

	i = 0;
	while (i++ < 31)
		signal(i, ft_signal_manager);
}
