/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perror1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:54:12 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/17 16:22:51 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "shell.h"

void	ft_not_a_cmd(char **av, char *err)
{
	if (ft_strcmp(*av, "env"))
		ft_printf("%s: Command not found: %s.\n", NAME, *av);
	else
		ft_printf("%s: %s: Command not found: %s.\n", NAME, *av, err);
}

void	ft_invalid_opt(char **av, char *err)
{
	ft_printf("%s: %s: %s: Invalid option.\n", NAME, *av, err);
	ft_built_in_usage(*av);
}

void	ft_target_not_found(char **av, char *err)
{
	ft_printf("%s: %s: %s: No such file or directory.\n", NAME, *av, err);
}

void	ft_arg_nbr_high(char **av, char *err)
{
	(void)err;
	ft_printf("%s: %s: Too many arguments.\n", NAME, *av);
}

void	ft_arg_nbr_low(char **av, char *err)
{
	(void)err;
	ft_printf("%s: %s: Argument expected.\n", NAME, *av);
}
