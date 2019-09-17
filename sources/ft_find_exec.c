/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 15:28:22 by tgouedar          #+#    #+#             */
/*   Updated: 2019/09/17 16:23:01 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdlib.h>
#include "bi_dispatcher.h"
#include "shell.h"
#include "libft.h"

t_dispatcher		g_built_in[] =
{
	{"echo", &ft_echo, NULL},
	{"cd", &ft_cd, &ft_cd_usage},
	{"env", &ft_env, NULL},
	{"setenv", &ft_setenv, &ft_set_usage},
	{"unsetenv", &ft_unsetenv, NULL},
	{"exit", &ft_exit, NULL},
	{NULL, NULL, NULL}
};

static int			ft_is_built_in(char *to_find, size_t *i)
{
	*i = 0;
	while (((g_built_in[*i]).name) && ft_strcmp((g_built_in[*i]).name, to_find))
		(*i)++;
	if ((g_built_in[*i]).name)
		return (1);
	return (0);
}

int					ft_built_in(t_env *env, char **av, int *status)
{
	size_t	i;

	if (ft_is_built_in(*av, &i))
		return ((g_built_in[i]).ft_(env, av, status));
	return (NOT_BI);
}

void				ft_built_in_usage(char *built_in)
{
	size_t	i;

	if (ft_is_built_in(built_in, &i) && ((g_built_in[i]).ft_usage))
		(g_built_in[i]).ft_usage();
}

char				*ft_build_path(char *path, char *exec)
{
	size_t	len;
	size_t	slash;
	char	*res;

	slash = ft_strlen(path);
	len = ft_strlen(exec);
	if (!(res = (char*)malloc(len + slash + 2)))
		ft_crisis_exit(MALLOC_ERR);
	ft_memcpy(res, path, slash);
	res[slash] = '/';
	ft_memcpy(res + slash + 1, exec, len);
	res[slash + len + 1] = '\0';
	free(path);
	return (res);
}

char				*ft_find_exec(t_env *env, char *to_find)
{
	DIR				*dir;
	struct dirent	*dirdata;
	char			*exec;

	if ((exec = ft_strrchr(to_find, '/')) && exec != to_find)
	{
		*exec = '\0';
		if ((dir = opendir(to_find)))
		{
			while ((dirdata = readdir(dir)))
				if (!(ft_strcmp(dirdata->d_name, exec + 1)))
				{
					closedir(dir);
					*exec = '/';
					return (ft_strdup(to_find));
				}
		}
		*exec = '/';
		closedir(dir);
	}
	else if (exec != to_find && (exec = ft_find_exec_path(env, to_find)))
		return (ft_build_path(exec, to_find));
	return (NULL);
}
