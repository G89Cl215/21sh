/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 13:06:53 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/08 14:59:41 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "signal.h"

void	ft_plop(int nbr)
{
	ft_printf("SIG_NB : %d.\n", nbr);
}

void	ft_sig_setup(void)
{
	size_t		i;

	i = 0;
	while (i++ < 31)
		signal(i, ft_plop);
}
