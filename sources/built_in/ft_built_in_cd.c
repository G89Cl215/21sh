/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in_cd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 13:33:11 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/17 16:21:54 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd.h"
#include "libft.h"
#include "shell.h"
#include <unistd.h>
#include <stdlib.h>

static int		ft_update_pwd(t_env *env, char *new_pwd, char flag)
{
	char	*old_pwd;
	char	pwd[PATH_MAX];

	if (chdir(new_pwd) == -1)
	{
		if (!(flag))
			free(new_pwd);
		return (TARGET_NOT_FOUND);
	}
	old_pwd = ft_get_env_var(env, "PWD");
	ft_set_env_var(env, "OLDPWD", old_pwd);
	getcwd(pwd, PATH_MAX);
	ft_set_env_var(env, "PWD", pwd);
	if (!(flag))
	{
		ft_set_env_var(env, "_", "cd");
		free(new_pwd);
	}
	else
		ft_set_env_var(env, "_", new_pwd);
	free(old_pwd);
	return (EXEC_SUCCESS);
}

static int		ft_cd_exec(t_env *env, char *new_pwd)
{
	char	*target;

	if (!(new_pwd))
	{
		if ((target = ft_get_env_var(env, "HOME")))
			return (ft_update_pwd(env, target, 0));
		ft_printf("%s: cd: HOME not set\n", NAME);
		return (UNSET_VAR);
	}
	if (!(ft_strcmp(new_pwd, "-")))
	{
		if ((target = ft_get_env_var(env, "OLDPWD")))
		{
			ft_putendl(target);
			return (ft_update_pwd(env, target, 0));
		}
		ft_printf("%s: cd: OLDPWD not set\n", NAME);
		return (UNSET_VAR);
	}
	else
		return (ft_update_pwd(env, new_pwd, 1));
	return (EXEC_SUCCESS);
}

static int		ft_find_target(size_t *i, char **av)
{
	size_t	len;

	*i = 1;
	if ((len = ft_tablen(av)) == 1)
		return (TARGET_FOUND);
	while (*i < len)
	{
		if (av[*i][0] == '-' && ft_strlen(av[*i]) > 1
		&& av[*i][ft_strspn(av[*i] + 1, CD_OPT)] != '\0')
			return (INVALID_OPTION);
		(*i)++;
	}
	*i = 1;
	while (*i < len)
	{
		if (av[*i][0] != '-' || !(ft_strcmp(av[*i], "-")))
			break ;
		(*i)++;
	}
	return (TARGET_FOUND);
}

int				ft_cd(t_env *env, char **av, int *status)
{
	size_t	target_index;

	*status = ft_find_target(&target_index, av);
	if (*status != TARGET_FOUND)
		return (EXEC_FAILURE);
	*status = ft_cd_exec(env, av[target_index]);
	return ((*status == EXEC_SUCCESS || *status == UNSET_VAR)
											? EXEC_SUCCESS : target_index);
}

void			ft_cd_usage(void)
{
	ft_putendl("cd: usage: cd [-L|-P] [dir]");
}
