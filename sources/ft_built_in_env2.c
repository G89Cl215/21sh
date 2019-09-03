/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in_env2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 20:31:33 by tgouedar          #+#    #+#             */
/*   Updated: 2019/07/02 22:24:27 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include "dispatcher.h"

static int	ft_create_all_var(t_env *env, char **av)
{
	size_t	i;
	char	*var_value;

	i = 0;
	while (av[++i])
	{
		var_value = ft_strchr(av[i], '=');
		*var_value = '\0';
		var_value++;
		ft_set_env_var(env, av[i], var_value);
	}
	return (EXEC_SUCCESS);
}

static int	ft_all_args_are_var(char **av)
{
	size_t	i;

	i = 0;
	while (av[++i])
		if (!(ft_strchr(av[i], '=')))
			break ;
	return (!(av[i]));
}

int			ft_setenv(t_env *env, char **av, int *status)
{
	size_t	len;

	len = ft_tablen(av);
	if (len == 1)
		return (ft_env(env, av, status));
	if (ft_all_args_are_var(av))
		return (ft_create_all_var(env, av));
	if (ft_strchr(av[1], '='))
		ft_printf("%s: setenv: No '=' allowed in variable name\n", NAME);
	else if (len < 4)
	{
		ft_set_env_var(env, av[1], (len == 3) ? av[2] : NULL);
		return (EXEC_SUCCESS);
	}
	else
		*status = ARG_NBR_HIGH;
	return (EXEC_FAILURE);
}

void		ft_set_usage(void)
{
	ft_putendl("setenv: usage: setenv VAR [VALUE]");
}

int			ft_unsetenv(t_env *env, char **av, int *status)
{
	size_t	len;

	len = ft_tablen(av);
	if (len == 2)
	{
		if (ft_unset_env_var(env, av[1]) == -1)
			ft_printf("%s: unsetenv: %s: No such variable in environnement\n",
												NAME, av[1]);
		return (*status = EXEC_SUCCESS);
	}
	if (len < 2)
		*status = ARG_NBR_LOW;
	if (len > 2)
		*status = ARG_NBR_HIGH;
	return (EXEC_FAILURE);
}
