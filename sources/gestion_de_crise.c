/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_de_crise.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:41:39 by tgouedar          #+#    #+#             */
/*   Updated: 2019/07/04 22:06:16 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "minishell.h"
#include "err_dispatcher.h"
#include <stdlib.h>

t_err	g_err[ERR_NBR] =
{
	{NOT_A_CMD, &ft_not_a_cmd},
	{INVALID_OPTION, &ft_invalid_opt},
	{TARGET_NOT_FOUND, &ft_target_not_found},
	{ARG_NBR_HIGH, &ft_arg_nbr_high},
	{ARG_NBR_LOW, &ft_arg_nbr_low},
	{ARG_NOT_NUM, &ft_arg_not_num},
};

void	ft_display_err(t_env *env, char **av, int status, int wrong_index)
{
	char	*err;
	size_t	i;

	i = 0;
	err = NULL;
	if (wrong_index > 0)
	{
		if (status == TARGET_NOT_FOUND && !(ft_strcmp(*av, "cd"))
			&& !(ft_strcmp(av[wrong_index], "-")))
			err = ft_get_env_var(env, "OLDPWD");
		else
			err = ft_strdup(av[wrong_index]);
	}
	while (i < ERR_NBR)
	{
		if (g_err[i].status == status)
			g_err[i].ft_perror(av, err);
		i++;
	}
	if (err)
		free(err);
}

void	ft_crisis_exit(int status)
{
	if (status == MALLOC_ERR)
		ft_printf("%s: A memory problem has occured.", NAME);
	exit(EXIT_FAILURE);
}
