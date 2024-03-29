/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perror2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:55:25 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/17 16:22:57 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "shell.h"

void	ft_arg_not_num(char **av, char *err)
{
	(void)err;
	ft_printf("%s: %s: %s: Numeric argument required\n", NAME, *av, av[1]);
}
